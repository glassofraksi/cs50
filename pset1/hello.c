#include <stdio.h>
#include <cs50.h>



int main(void)

{
    string name;

    name = get_string("Please Enter Your Name: ");  //ask for user input

    printf("Hello, %s\n", name); // print on screen


}