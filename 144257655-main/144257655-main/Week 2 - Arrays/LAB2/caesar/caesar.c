#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    int k = atoi(argv[1]);
    if (k == 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    string text = get_string("plaintext: ");
    char ciphertext[strlen(text)];
    int i;
    for (i = 0; i < strlen(text); i++)
    {
        if (isupper(text[i]))
        {
            ciphertext[i] = ((text[i] - 65) + k) % 26 + 65;
        }
        else if (islower(text[i]))
        {
            ciphertext[i] = ((text[i] - 97) + k) % 26 + 97;
        }
        else
        {
            ciphertext[i] = text[i];
        }
    }
    ciphertext[i] = '\0';
    printf("ciphertext: %s\n", ciphertext);
}