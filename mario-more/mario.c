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
        // this loop is to iterate dots and Print dots
        for (int j = 1; j <= n - i; j++)
        {
            printf(" ");
        }
        // This loop is to iterate hashes and Printing hashes
        for (int k = 1; k <= i; k++)
        {
            printf("#");
        }
        // This is for double spaces
        printf("  ");
        // this is to print hashes of right aligned pyramid
        for (int l = 1; l <= i; l++)
        {
            printf("#");
        }
        // this is to print hashes of left aligned pyramid

        printf("\n");
    }
}