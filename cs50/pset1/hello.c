#include <stdio.h>
#include <cs50.h>


int main(void)
{
    string name = get_string("What's your name? "); // ask a input
    printf("hello, %s\n", name);

}