#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

float calc_hours(int hours[], int weeks, char output);

int main(void)
{
// Se cere numarul total de saptamani de cand studiezi CS50 si se salveaza in variabila "weeks"
    int weeks = get_int("Number of weeks taking CS50: ");
// Se creaza un array numit "hours" care are ca numar de elemente numarul de saptamani de mai sus
    int hours[weeks];

// Se introduc in locatiile array ul "hours" numarul de ore pentru fiecare saptamana in parte
    for (int i = 0; i < weeks; i++)
    {
        hours[i] = get_int("Week %i HW Hours: ", i);
    }

// Se declara variabila "output" de tip char
    char output;
// Se creaza un loop care te obliga sa introduci litera T sau A
    do
    {
// Se foloseste functia "toupper" pentru a capitaliza literele in cazul in care sunt scrise in lower case
        output = toupper(get_char("Enter T for total hours, A for average hours per week: "));
    }
    while (output != 'T' && output != 'A');

    printf("%.1f hours\n", calc_hours(hours, weeks, output));
}


float calc_hours(int hours[], int weeks, char output)
{

    int sum = 0;
    for (int i = 0; i < weeks; i++)
    {
        sum += hours[i];
    }

    float avarage = sum / (float)weeks;

    char x = 'T', y = 'A';

    if (output == x)
    {
        return sum;
    }
    else if (output == y)
    {
        return avarage;
    }
    return 0;
}
