#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h> // atoi - convert a string to an int
#include <string.h>

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    else
    {
        // if there are 2 arguments checks if all the second argument contains digits
        string m = argv[1];
        for (int i = 0; i < strlen(m); i++)
        {
            if (isdigit(m[i]) == 0)
            {
                printf("Usage: ./caesar key\n");
                return 1;

            }
        }
    }

    int k = atoi(argv[1]); // convert string "argv[1]" to an integer

    if (k < 0)
    {
        printf("Please, enter positive number\n"); // if k is negatif number return 1
        return 1;
    }

    string pt;
    pt = get_string("plaintext:  ");
    printf("ciphertext: ");

    for (int i = 0, n = strlen(pt); i < n; i++)
    {
        if (isalpha(pt[i]))
        {

            if (islower(pt[i]))
            {
                printf("%c", (((pt[i] + k) - 97) % 26) + 97); // c'i = (p'i + k) % 26
            }

            else if (isupper(pt[i]))
            {
                printf("%c", (((pt[i] + k) - 65) % 26) + 65);// c'i = (p'i + k) % 26
            }
        }

        else
        {
            printf("%c", pt[i]);
        }
    }
    printf("\n");

    return 0;
}