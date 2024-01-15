#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



// Declaration of functions
bool only_digits(string text);
char rotate(char c, int key);

//  Main function
int main(int argc, string argv[])
{
    string plaintext;

// Condition for only one int argument
    if (argc == 2 && only_digits(argv[1]))
    {
        plaintext = get_string("plaintext: ");
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
// Converting string argument to int
    int key = atoi(argv[1]);

// Calling the rotate function for encripting characters and printing the result
    char c = '0';
    printf("ciphertext: ");

    for (int i = 0; i < strlen(plaintext); i++)
    {
        c = rotate(plaintext[i], key);
        printf("%c", c);
    }
    printf("\n");
}

// Function for checking argv to accept only digits
bool only_digits(string text)
{
    bool digit = false;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isdigit(text[i]))
        {
            digit = true;
        }
        else
        {
            digit = false;
            break;
        }
    }
    return digit;
}

// Rotate function to rotate characters
char rotate(char c, int key)
{
// Declaring variables
    char x = c;
    char e = '0';
    int formula = 0;
    char t = 0;

// Condition for checking if the character is alphanumeric one
    if (isalpha(x))
    {
        if (islower(x))
        {
            e = x - 'a';
            formula = (e + key) % 26;
            t = formula + 'a';
        }
        else if (isupper(x))
        {
            e = x - 'A';
            formula = (e + key) % 26;
            t = formula + 'A';
        }
    }
    else
    {
        t = x;
    }
    return t;

}