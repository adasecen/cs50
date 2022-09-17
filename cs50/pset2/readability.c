#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h> // use a round

//index = 0.0588 * L - 0.296 * S - 15.8
//The text the user inputted has 65 letters, 4 sentences, and 14 words.
//65 letters per 14 words is an average of
//about 464.29 letters per 100 words (because 65 / 14 * 100 = 464.29).
//And 4 sentences per 14 words is an average of about 28.57 sentences
//per 100 words (because 4 / 14 * 100 = 28.57).
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
float count1 = 0;
float count2 = 1;
float count3 = 0;

// ascii ! = 33, . = 46, ? = 63
int main(void)
{
    // Get input words from both
    string text = get_string("Text: ");

    count_letters(text);
    count_words(text);
    count_sentences(text);

    //printf("%f\n", count1);//letter
    //printf("%f\n", count2);//word
    //printf("%f\n", count3);//cümle

    float L = (count1 / count2 * 100);
    float S = (count3 / count2 * 100);
    //printf("%f\n", L);
    //printf("%f\n", S);

    float index = 0.0588 * L - 0.296 * S - 15.8;

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(index));
    }
}

int count_letters(string text)
{
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            count1++;
        }
    }

    return count1;

}

int count_words(string text)
{
    for (int s = 0; s < strlen(text); s++)
    {
        if (isspace(text[s])) //
        {
            count2++;
        }
    }

    return count2;
}

int count_sentences(string text)
{
    for (int a = 0; a < strlen(text); a++)
    {
        if (text[a] == '!' || text[a] == '.' || text[a] == '?')
        {
            count3++;
        }

    }

    return count3;

}