// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;
unsigned int hash_code;
unsigned int word_count;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    hash_code = hash(word);
    node *kafka = table[hash_code];
    while (kafka != 0)
    {
        if (strcasecmp(word, kafka->word) == 0)
        {
            return true;
        }
        kafka = kafka->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned long hash_value = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        hash_value += tolower(word[i]);
        hash_value = (hash_value * tolower(word[i])) % N;
    }
    return hash_value % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }
    char buffer[LENGTH + 1];
    while (fscanf(file, "%s", buffer) != EOF)
    {
        node *temp = malloc(sizeof(node));
        if (temp == NULL)
        {
            return false;
        }

        strcpy(temp->word, buffer);
        hash_code = hash(buffer);
        temp->next = table[hash_code];
        table[hash_code] = temp;
        word_count++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return (word_count > 0) ? word_count : 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *kafka = table[i];
        while (kafka)
        {
            node *temp = kafka;
            kafka = kafka->next;
            free(temp);
        }

        // if(kafka == NULL && i == N-1)
        // {
        //     return true;
        // }
    }
    return true;
}
