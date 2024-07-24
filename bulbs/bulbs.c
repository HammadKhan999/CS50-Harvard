#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;
// function to print the bulbs
void print_bulb(int bit);

// main function
int main(void)
{
    // getting input string from user
    string text = get_string("Enter Text: ");
    int n = strlen(text);
    // declaring array to store the ascii of entered string (character-wise)
    int ascii_text[n];
    // declaring array to store the binary of ascii of each character
    int bit[n][BITS_IN_BYTE];
    // for loop to convert character to it's ascii
    for (int i = 0; i < n; i++)
    {
        ascii_text[i] = (int) text[i];

        // for loop to convert the ascii to binary representation and store in bit array
        for (int j = BITS_IN_BYTE - 1; j >= 0; j--)
        {
            bit[i][j] = (ascii_text[i] >> j) % 2;
        }
    }
    // for loop to print the bulbs for corresponding characters stored in bit variable
    for (int l = 0; l < n; l++)
    {
        for (int k = BITS_IN_BYTE - 1; k >= 0; k--)
        {
            print_bulb(bit[l][k]);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
