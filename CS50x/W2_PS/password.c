// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>


bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    string word = password;

    int leng = strlen(password);

    bool lowercase = false;
    bool uppercase = false;
    bool alphanumeric = false;
    bool sign = false;
    bool digit = false;

    for (int i = 0; i < leng; i++)
        {
            if (islower(word[i]) )
            {
                lowercase = true;
                break;
            }
            else
            {
                lowercase = false;
            }
        }

    for (int i = 0; i < leng; i++)
        {
            if (isupper(word[i]))
            {
                uppercase = true;
                break;
            }
            else
            {
                uppercase = false;
            }
        }

        for (int i = 0; i < leng; i++)
        {
            if (isalnum(word[i]))
            {
                alphanumeric = true;
                break;
            }
            else
            {
                alphanumeric = false;
            }
        }

        for (int i = 0; i < leng; i++)
        {
            if (ispunct(word[i]))
            {
                sign = true;
                break;
            }
            else
            {
                sign = false;
            }
        }

        for (int i = 0; i < leng; i++)
        {
            if (isdigit(word[i]))
            {
                digit = true;
                break;
            }
            else
            {
                digit = false;
            }
        }


    if (lowercase && uppercase && alphanumeric && sign && digit)
    {
            return true;
    }

    return false;
}
