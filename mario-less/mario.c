#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Enter Height: ");
    }
    while (n < 1 || n > 8);
    // This loop is to iterate rows
    for (int i = 1; i <= n; i++)
    {
        // this loop is to iterate and increment spaces and Print dots
        for (int j = 1; j <= n - i; j++)
        {
            printf(" ");
        }
        // this loop is to iterate and increment hashes and print dots
        for (int k = 1; k <= i; k++)
        {
            printf("#");
        }
        // This is the first loop that starts every row on new line
        printf("\n");
    }
}