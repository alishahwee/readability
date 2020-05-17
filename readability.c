#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int ColemanLiau_Index(int letters, int words, int sentences);

int main(void)
{
    string text = get_string("Text: ");

    int letters = count_letters(text);

    int words = count_words(text);

    int sentences = count_sentences(text);

    ColemanLiau_Index(letters, words, sentences);
}

int count_letters(string text)
{
    int count = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]) != 0) // Function searches for any alphabetic character (upper or lowercase).
        {
            count++;
        }
    }

    return count;
}

int count_words(string text)
{
    int count = 1; // Not zero by default to take in account of the last word (assumes that there is no space after).

    for (int i = 0; i < strlen(text); i++)
    {
        if (isblank(text[i]) != 0)
        {
            count++;
        }
    }

    return count;
}

int count_sentences(string text)
{
    int count = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == 33) // If the text has a "!".
        {
            count++;
        }
        else if (text[i] == 46) // If the text has a ".".
        {
            count++;
        }
        else if (text[i] == 63) // If the text has a "?".
        {
            count++;
        }
    }

    return count;
}

int ColemanLiau_Index(int letters, int words, int sentences)
{
    // Cast values as floats to avoid truncation.
    float L = (float) letters / (float) words * 100;
    float S = (float) sentences / (float) words * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;

    if (index < 1)
    {
        return printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        return printf("Grade 16+\n");
    }
    else
    {
        return printf("Grade %.0f\n", round(index));
    }
}