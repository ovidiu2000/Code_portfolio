// Practice writing a function to find a max value

#include <cs50.h>
#include <stdio.h>

int max(int array[], int n);

int main(void)
{
    int n;
    do
    {
        n = get_int("Number of elements: ");
    }
    while (n < 1);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = get_int("Element %i: ", i);
    }

    printf("The max value is %i.\n", max(arr, n));
}

// TODO: return the max value
int max(int array[], int n)
{

    for (int i = 0; i < n; i++)
    {
        if (array[i] > array[i + 1])
        {
            for (int x = 0; x < n - 1; x++)
            {
                int num = array[x];

                if (array[x] > array[x + 1])
                {
                    array[x] = array[x + 1];
                    array[x + 1] = num;
                }
            }

        }
    }
    return array[n - 1];
}
