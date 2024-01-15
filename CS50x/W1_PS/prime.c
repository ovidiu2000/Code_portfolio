    #include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{
    int n = number;
    int k = 0;
    int j = 0;
    int i;
    for (i = 2; i < n; i++)
    {

        k = n % i;
        if (k == 0)
        {
            break;
        }
    }

        j = k;

    if (j == 0 && n == 2)
    {
        return true;
    }
    else if ( j == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}
