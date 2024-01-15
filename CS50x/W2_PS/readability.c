#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


// Functions prototype
int count_letters(string letters);
int count_words(string words);
int count_sentences(string sentences);

int main(void)
{
// Get input from user
    string text = get_string("Text: ");
    int letters, words, sent;

// Call functions
    letters = count_letters(text);
    words = count_words(text);
    sent = count_sentences(text);

// Calculate Colman - Liau index
    float clindex = ((float)letters / words) * 100 * 0.0588 - ((float)sent / words) * 100 * 0.296 - 15.8;

// Printing results
    if (clindex < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (clindex > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int)round(clindex));
    }
}


// Count letters function
int count_letters(string letters)
{
    int count = 0;

    for (int i = 0; i < strlen(letters); i++)
    {
        if (isalpha(letters[i]) != 0)
        {
            count++;
        }
    }
    return count;
}


//Count words function
int count_words(string words)
{
    int count = 1;

    for (int i = 0; i < strlen(words); i++)
    {
        if (words[i] == ' ')
        {
            count++;
        }
    }
    return count;
}

//Count sentences function
int count_sentences(string sentences)
{
    int count = 0;

    for (int i = 0; i < strlen(sentences); i++)
    {
        if (sentences[i] == '!' || sentences[i] == '?' || sentences[i] == '.')
        {
            count++;
        }
    }
    return count;
}