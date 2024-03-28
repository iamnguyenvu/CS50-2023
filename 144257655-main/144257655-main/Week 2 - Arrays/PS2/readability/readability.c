#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    float L = (letters / (float) words) * 100;
    float S = (sentences / (float) words) * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 1 && index <= 16)
    {
        printf("Grade %i\n", (int) index);
    }
    else
    {
        printf("Grade 16+\n");
    }
}

int count_letters(string text)
{
    int letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
            letters++;
    }
    return letters;
}

int count_words(string text)
{
    int words = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i + 1] == ' ')
            words++;
    }
    return words + 1;
}

int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i + 1] == '.' || text[i + 1] == '!' || text[i + 1] == '?')
            sentences++;
    }
    return sentences;
}