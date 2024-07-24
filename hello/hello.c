#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // taking name as input from user
    string name = get_string("What's your name? ");
    // printing hello <User name>
    printf("Hello, %s\n", name);
}