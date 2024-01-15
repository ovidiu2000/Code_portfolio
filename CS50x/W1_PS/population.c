#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n = 0;
    int fpop;
    int k = 0;
    // TODO: Prompt for start size
    do
    {
        n = get_int("Starting population : ");
    }
    while (n < 9);

    // TODO: Prompt for end size

    do
    {
        fpop = get_int("Final Population: ");
    }
    while (fpop < n);

    // TODO: Calculate number of years until we reach threshold

    for (k = 0; n < fpop; k++)
    {
        n = n + (n / 3) - (n / 4);
    }

    // TODO: Print number of years
    printf("Years: %i\n", k);
}
