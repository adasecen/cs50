#include <cs50.h> // use get_long
#include <stdio.h>
#include <math.h>

int main(void)
{
    long n; //input
    long n_size = 0; //size of the input
    do
    {
        n = get_long("Number: ");
    }
    while (n < 0);

    long tempInput = n;
    while (tempInput != 0)
    {
        tempInput = tempInput / 10;
        n_size++;
    }


    if ((n_size) != 13 && (n_size) != 16 && (n_size) != 15)
    {
        printf("INVALID\n");
        return 0;
    }

    long arrayInput[n_size]; //array declare

    tempInput = n;
    for (long i = 0; i < n_size; i++)
    {
        arrayInput[n_size - i - 1] = tempInput % 10;
        tempInput = tempInput / 10;
    }


    long sum = 0;
    long counter = 0;
    long d1, d2;
    for (long j = 1; j < n_size; j += 2) // long sum1 *2
    {
        counter = arrayInput[n_size - j - 1] * 2; // long sum1 *2
        if (counter < 10)
        {
            d2 = counter;
            printf("%li\n", counter); // long sum1 < 10
        }
        else
        {
            d1 = counter % 10;
            counter = d1 + 1;
        }
        sum += counter;
    }
    printf("%li\n", sum);

    long summ = 0;
    long counterr = 0;
    for (long j = 0; j < n_size; j += 2)
    {
        counterr = arrayInput[n_size - j - 1];
        summ += counterr;  // long sum2

    }
    printf("%li\n", summ);


    long sumt = sum + summ;  // total sum = sum1+ sum2
    printf("%li\n", sumt);

    if ((n_size == 15 && arrayInput[0] == 3) && (arrayInput[1] == 4 || arrayInput[1] == 7) && (sumt % 10 == 0))
    {

        printf("AMEX\n"); // amex size:15 
    }

    else if ((n_size == 16 && arrayInput[0] == 5) && ((arrayInput[1] == 2 || arrayInput[1] == 1 || arrayInput[1] == 4
             || arrayInput[1] == 3 || arrayInput[1] == 5)) && (sumt % 10 == 0))
    {

        printf("MASTERCARD\n");

    }

    else if (((n_size == 13 && arrayInput[0] == 4) || (n_size == 16 && arrayInput[0] == 4)) && (sumt % 10 == 0))
    {

        printf("VISA\n");

    }
    else
    {
        printf("INVALID\n");
    }


}
