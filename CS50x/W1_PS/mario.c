#include<cs50.h>
#include<stdio.h>

int main(void)

{
// Asking for number loop
    int n;
    do
    {
        n = get_int("Input number from 1 to 8\n");
    }
    while (n <= 0 || n > 8);

// Create the main loop
    for (int i = 0; i < n; i++)
    {
        for (int k = n - 1; k > i; k--)
//Create the right align loop
        {
            printf(" ");
        }
// Create the hash loop
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        printf("  ");

// Create the right side

        for (int m = 0; m <= i; m++)
        {
            printf("#");
        }
        printf("\n");

    }
}
