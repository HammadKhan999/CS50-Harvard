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

// Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // using hash function to get the number at which we have to store the word
    int index = hash(word);
    // initializing head with the index of input word first letter
    node *head = table[index];
    node *cursor = head;
    cursor = head;
    // comparing all the words of dictionary with the input word using strcasecmp
    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    char word_from_file[LENGTH + 1];
    // Opening the dictionary file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }
    // reading the words from file using fscanf function
    while (fscanf(file, "%s,", word_from_file) != EOF)
    {
        // creating nodes of linked list to be stored at indexes of table array
        node *head = malloc(sizeof(node));
        // checking if memory is allocated
        if (head == NULL)
        {
            fclose(file);
            return false;
        }

        // copying all the words from dictionary to structure variable variable
        strcpy(head->word, word_from_file);

        // storing those word's w.r.t their hashes
        int index = hash(head->word);
        head->next = table[index];
        table[index] = head;
    }

    // closing the dictionary file
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // initializing cursor node
    node *cursor = table[0];
    int size_of_dictionary = 0;

    // using for loop to iterate through each index of table array and count words of each linked list
    for (int i = 0; i < N; i++)
    {
        cursor = table[i];
        while (cursor != NULL)
        {
            size_of_dictionary++;
            cursor = cursor->next;
        }
    }

    // returning size of dictionary
    return size_of_dictionary;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // declaring required nodes
    node *head = table[0];
    node *cursor = head;
    node *tmp = head;

    // iterating through each index of table and freeing each node of linked list
    for (int i = 0; i < N; i++)
    {
        cursor = table[i];
        // accessing each node of the linked list at ith index
        while (cursor != NULL)
        {
            tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }

    return true;
}
