// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

    // The "replace" function
string replace (string word);



int main(int argc, string argv[])
{

    // Condition for accepting only one single command-line argument
    while (argc != 2)
    {
        printf("Invalid number of command-line arguments\n");
        return 1;
    }

    string word = argv[1];
    printf("%s\n", replace(word));

    // Exit code if everything is fine
    return 0;
}


string replace(string word)
{

    string text = word;
    int lenght = strlen(word);

    for (int i = 0; i < lenght; i++)
    {
        switch (word[i])
        {
            case 'a':
                text[i] = '6';
                break;
            case 'e':
                text[i] = '3';
                break;
            case 'i':
                text[i] = '1';
                break;
            case 'o':
                text[i] = '0';
                break;
        }
    }

    return text;
}
