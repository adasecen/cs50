#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./substitution key\n"); // if argc != 2 ; mistake
        return 1;
    }

    string o = argv[1];

    if (strlen(o) != 26)  // if argc lenght != 26 ; mistake
    {
        printf("Key must contain 26 characters.");
    }
    else
    {
        string m = argv[1]; // string argv
        for (int i = 0; i < strlen(m); i++)
        {
            if (isalpha(m[i]) == 0) // if don't use a alphabetical character --> isalpha == 0 ; and 0 == false; false and false == false
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
    }

    int matches = 0;

    for (int i = 0; i < 26; i++) // if you use the same character more than once
    {
        for (int j = 0; argv[1][j] != '\0'; j++)
        {

            if (argv[1][j] == argv[1][i])
            {
                matches++;
            }
        }
    }

    if (matches != 26)
    {
        printf("Do not repeat letters in key\n");
        return 1;
    }

    string alp = "abcdefghijklmnopqrstuvwxyz"; //lower alphabetical
    string ALP = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // upper alphabetical

    string pt = get_string("plaintext:  "); // size a string

    printf("ciphertext: ");

    for (int i = 0; i < strlen(pt); i++) // character loop a lenght
    {

        for (int j = 0; j < 26; j++) // for loop a find a pt in alph
        {

            if (isalpha(pt[i])) // character is a alphabetical
            {
                if (islower(pt[i])) //character is a lower
                {
                    if (pt[i] == alp[j]) // plaintext i character == alp j and plaintext == alpj
                    {
                        char Temp = tolower(o[j]);
                        printf("%c", Temp);
                    }
                }

                if (isupper(pt[i])) //character is a upper
                {

                    if (pt[i] == ALP[j]) // plaintext i character == alp j and plaintext == alpj
                    {
                        char Temp = toupper(o[j]);
                        printf("%c", Temp);
                    }
                }
            }

            else //// character is not a alphabetical
            {
                printf("%c", pt[i]);
                break;
            }
        }
    }
    printf("\n");
    return 0;
}