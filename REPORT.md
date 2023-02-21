# ECS 150 Winter 2023
# Project 1: Implementing a simple shell from scratch
## Abhash Sapkota, Sina Havaeeahari
 
Our workflow followed the suggested stages over the course of several days.

### Parsing Arguments
For this phase of the project, we created a function exec_regular command that   
is in charge of running system commands with or without any arguments. To parse   
the arguments, we have created a struct that holds the main command such as (ls,   
date, etc.) and a linked list of the arguments (-l, -u, etc.). And in order to   
convert from user input to this structure, we created function 'init_command'  
which takes a string, and processes it by using the function 'remove_space' that  
eliminates all the extra space before, in the middle, and after the string and  
strips it. 

`struct processed_command *init_command(char *input_cmd)`

### Function Calls

The processed command is fed to a loop that breaks down the string using  
'strchr()' function using the space separation and fills the linked list with  
the broken down arguments. Then the command is passed to the function  
'check_errors' which checks for all of the possible parsing errors and the exec  
will be aborted in case of failure.   
Then, the struct of processed command is passed to the function 'get_args_array'  
which takes in a the struct and creates an array of arguments with by putting  
the main command in index 0, arguments in the following indicies and a 'NULL'  
argument for the last index which is the format that execv needs for executing  
the process. Then the array is passed to  to which uses $PATH and executes the  
command. In case the execvp fails, a not blocking error will be output which  
specifies that the command is not found. After determining the type of command,  
it is passed onto their respective functions:  

```
void exec_dir_process(char *command);
void exec_regular_process(char *command);
void exec_redirection(char *command);
void exec_piping_process(char *command);
```
### Piping

Commands with multiple arguments that require piping are dealt by the function  
'exec_piping_process' which is linked to 'prep_piping_process'.  

- Error handling: First the user input is sent to the check_errors function  
which checks for any parsing issues such as a missing command and it exits the  
function if any error is detected.<br>
- Then similar to phase 2, all extra spaces in the input command are removed in  
 addition with 'add_space' function which handles the cases where user does not  
 put a space for '|' (date|tr 2 1).<br>
- Then we split the command to multiple commands whenever a '|' is detected.  
This way we also keep count of number of processes and number of pipes to be  
created. <br>
- function 'get_pipe_args_array' breaks down user input with '|' and similar to  
 a single process command, it creates an array of processed_command struct for  
 every process in the user input. <br>
- Then for each process a pipe is created.<br>
- In this section, we enter the loop that is in charge of handling each command  
 and feeding it through the pipes to the next process and so on; For each  
 process, we connect the write end of the current command's file descriptor to  
 the read end of the next command and the read end of the current process is  
 connected to the write end of the previous process unless the current command  
 is the first command in the list. Lastly, we we close all of the pipes and  
 begin executing each command using execvp. If the last process is encountered  
 and it requires output redirection, the command is sent to 'exec_redirection'  
 which is in charge of executing a process and outputting it to the specified  
 file. After the loop is existed and all the processes are launched, we enter  
 the parent process. Since by forking, file descriptors are also duplicated, we  
 close all of them. Then we wait for all of the processes to execute by checking  
 their status and lastly print the 'completion' result for the user. If any of  
 the processes fail, they will be flagged in the terminal output.  


### Error Handling

This is a dynamic shell, and it will inadvertently will have to deal with  
unexpected conditions, such as user not providing a proper command, having too  
many arguments, not having proper access to asked resources, just to name a few.  
To deal with these errors, we had to first identify them, and then point the  
program in the right direction to handle them. The several error conditions were  
enumerated and provided to the following function which printed the respective  
problem to notify the user.  

`void handle_errors(int error)`

### Background Processes

No shell would be complete without the ability to push certain tasks to the  
background. By providing the character '&' at the end, the user is able to tell  
the system to push that specific task into the background. The easy part was to  
utilize the WNOHANG option in the waitpid call of the parent process. This makes  
sure that the parent is not blocked and shell will be ready to take next input  
right away. The hard part was to be notified when the tasks previously pushed  
into the background were complete. For this purpose, we utilized the signal()  
function to listen for the SIGCHLD signal which is outputted in case of such  
completion, and simply print that it has completed. Sigaction() would have been  
a more powerful function but signal() was enough for our purposes.  

### Testing

Any program needs to be thoroughly tested before being deployed. We utilized all  
the mentioned test cases in the assignment prompt, as well as the testing script  
provided. As a final safeguard, we also tested the program in CSIF computers and  
made sure it ran smoothly.

### Summary and Sources

The shell is at the heart of any operating system and helps bridge the gap  
between user and OS services by providing an easy interface to communicate.  
For our first project in ECS 150, we were tasked with implementing a simple yet  
powerful shell. Completion of this project has helped us better understand  
various system processes and how they interact in the background to make user  
experience pleasant.   

Furthermore, even though it is a shell from scratch, we still have to rely on  
the collective work and knowledge throughout the years to reach our goals. We  
would like to express our gratitude to Professor Porquet-Lupine for his lecture  
notes as well as the following online sources we have utilized:

- [signal(7) — Linux manual page](https://man7.org/linux/man-pages/man7/signal.7.html)
- [How to get the path to the current file (pwd) in Linux from C?](https://stackoverflow.com/questions/16285623/how-to-get-the-path-to-the-current-file-pwd-in-linux-from-c)
- [Implementing pipe in C](https://stackoverflow.com/questions/21914632/implementing-pipe-in-c)
- [Working with multiple pipes](https://www.youtube.com/watch?v=NkfIUo_Qq4c)
