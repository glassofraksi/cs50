#ECS 150 Winter 2023
#Project 1: Implementing a simple shell from scratch

##Abhash Sapkota, Sina Havaeeahari
 
Our workflow followed the suggested stages over the course of several days.

###Error Handling

This is a dynamic shell, and it will inadvertently will have to deal with unexpe
cted conditions, such as user not providing a proper command, having too many ar
guments, not having proper access to asked resources, just to name a few. To dea
l with these errors, we had to first identify them, and then point the program i
n the right direction to handle them. The several error conditions were enumerat
ed and provided to the following function which then printed the respective prob
lem to notify the user

`void handle_errors(int error)`

###Background Processes

No shell is complete without the ability to push certain tasks into the backgrou
nd. By providing the character '&' at the end, the user is able to tell the syst
em to push that specific task into the background. The easy part was to utilize 
the WNOHANG option in the waitpid call of the parent process. This makes sure th
at the parent is not blocked and
shell will be ready to take another input right away. The hard part was to be no
tified when the tasks previously pushed into the background were complete. For t
his purpose, we utilized the signal() function to listen for the SIGCHLD signal 
which is outputted in case of such completion, and simply print that it has comp
leted. Sigaction() would have been a more powerful function but signal() was eno
ugh for our purposes.  

###Testing

Any program needs to be thoroughly tested before being deployed. We utilized all
 the mentioned test cases in the assignment prompt, as well as the testing scrip
t provided. As a final safeguard, we also tested the program in CSIF computers a
nd made sure it ran smoothly.

###Summary and sources

The shell is at the heart of any operating system and helps bridge the gap betwe
en user and OS services by providing an easy interface to communicate.
For our first project in ECS 150, we were tasked with implementing a simple yet 
powerful shell. Completion of this project has helped us better understand vario
us
system processes and how they interact in the background to make user experience
pleasant.

Furthermore, even though it is a shell from scratch, we still have to rely on th
e collective work and knowledge passed throughout the years to reach our goals. We 
would like to express our gratitude to Professor Porquet-Lupine for his lecture notes
as well as the following online sources we have utilized:

- [signal(7) — Linux manual page](https://man7.org/linux/man-pages/man7/signal.7.html)
