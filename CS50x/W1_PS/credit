#include <cs50.h>
#include <stdio.h>
#include <math.h>
// Variable and function declaration
int evenpart(long even);
int oddpart(long odd);
int fullnumber(int even, int odd);


int main(void)

{
// Program
    long n = get_long("Number: ");
    int evencheck = evenpart(n);
    int oddcheck = oddpart(n);
    int checksum = fullnumber(evencheck, oddcheck);
    long digits = 0;


// Conditions
// 13 Numbers Visa
    if (n > 999999999999 && n < 10000000000000)
    {
        digits = n / 1000000000000;
        if (digits == 4 && checksum == 0)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }

    }

// 15 Numbers Amex
    else if (n > 99999999999999 && n < 1000000000000000)
    {
        digits = n / 10000000000000;
        if (digits == 34 || (digits == 37 && checksum == 0))
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }

// 16 numbers Mastercard
    else if (n > 999999999999999 && n < 10000000000000000)
    {
        digits = n / 100000000000000;

        if (digits == 51 || (digits == 52 || (digits == 53 || (digits == 54 || (digits == 55 && checksum == 0)))))
        {
            printf("MASTERCARD\n");
        }

        else
        {
            printf("INVALID\n");
        }
        digits = n / 1000000000000000;
// 16 numbers Visa
        if (digits == 4 && checksum == 0)
        {
            printf("VISA\n");
        }
    }

    else
    {
        printf("INVALID\n");
    }
}

// Function declaration
// Even part function
int evenpart(long even)

{
// Variables
    long number = even;
    long k = 0;
    long n = 100;
    long h = 10;
    int evenpart = 0;
    int split = 0;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            k = (number % n) / h;
            n = n * 100;
            h = h * 100;
        }

        for (int m = 0; m < 1; m++)
        {
            int split1 = (k * 2) / 10;
            int split2 = (k * 2) % 10;
            split = (split1 + split2);
        }

        evenpart = evenpart + split;
    }

    return evenpart;
}
// Odd part function
int oddpart(long odd)
{
// Variables
    long number = odd;
    long k = 0;
    long n = 10;
    long h = 1;
    int oddpart = 0;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            k = (number % n) / h;
            n = n * 100;
            h = h * 100;
        }
        oddpart = oddpart + k;
    }
    return oddpart;

}
// Full number function
int fullnumber(int even, int odd)
{
    int evenodd = even + odd;
    int fullnumber = evenodd % 10;
    return fullnumber;
}
