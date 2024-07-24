#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, string argv[])

{
    // declaring required variables
    int key;
    string plain_text;
    int len_plain = 0;
    // storing the command line argument in s as string
    string s = argv[1];
    // checking the required conditions and printing corresponding messages
    if (argc > 2 || argc < 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // iterating to check that entered key is digit
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (!(isdigit(s[i])))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    // converting key from string to int
    key = atoi(s);
    printf("Key: %i\n", key);
    // taking plain text input from user
    plain_text = get_string("plaintext:");
    // storing size of plain text to be used for cipher text
    len_plain = strlen(plain_text);
    char cipher_text[len_plain];
    // iterating over whole string and applying the given formula to cipher the original text
    for (int i = 0, n = strlen(plain_text); i <= n; i++)
    {
        // applying conditions for plain texts and performing corresponding operations
        if (isupper(plain_text[i]))
        {

            cipher_text[i] = ((plain_text[i] - 'A' + key) % 26 + 'A');
            // printf("ct: %i\n",ct[i]);
            // ct[i] += 65;
            // cipher_text[i] = (char) ct[i];
        }

        else if (islower(plain_text[i]))
        {

            cipher_text[i] = ((plain_text[i] - 'a' + key) % 26 + 'a');
            // ct[i] += 65;
            // cipher_text[i] = (char) ct[i];
        }
        else if (isdigit(plain_text[i]))
        {
            cipher_text[i] = plain_text[i];
        }
        else if (ispunct(plain_text[i]))
        {

            cipher_text[i] = plain_text[i];
        }
        else if (isspace(plain_text[i]))
        {

            cipher_text[i] = plain_text[i];
        }
        else
        {

            cipher_text[i] = plain_text[i];
        }
    }
    printf("ciphertext: %s\n", cipher_text);

    return 0;
}
