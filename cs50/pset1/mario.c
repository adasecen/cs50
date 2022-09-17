#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }

    while (height < 1 || height > 8); // Positive integer and <= 8

// int column = 1 because 1. column full space
    for (int column = 1; column <= height; column++)
    {

        for (int space = 0; space < (height - column); space++)
        {
            printf(" ");

        }

        for (int has = 0; has < column; has++) // has loop
        {

            printf("#");
        }

        printf("  "); // end two has spacee

        for (int has = 0; has < column; has++) // has loop end 2
        {

            printf("#");

        }
        printf("\n");
    }
}