#include <cs50.h>
#include <math.h>
#include <stdio.h>

// main function
int main(void)
{
    // forward declaration of required variables and functions
    long card_number;
    long get_cardnumber(void);
    int check_sum(int card_number);
    void visa_num(long card_number);
    void american_num(long card_number);
    void master_num(long card_number);
    int card_number_len;

    // do while loop to check whether the number entered follows credit card number basic criteria of number of digits
    do
    {
        card_number = get_cardnumber();
        card_number_len = log10(card_number) + 1;
    }
    while (card_number_len != 13 && card_number_len != 15 && card_number_len != 16);
    // using check_sum function to verify whether entered number is valid credit card number or not
    int sum = check_sum(card_number);
    // loop for validity of credit card
    if (sum != 0)
    {
        printf("INVALID\n");
    }

    else
    {
        printf("VALID\n");
    }
    // calling functions of different credit cards to validate
    visa_num(card_number);
    american_num(card_number);
    master_num(card_number);
}

// funciton to get the number from user
long get_cardnumber(void)
{
    long card_number = get_long("Enter Credit card number: ");
    return card_number;
}
// function to verify whether the number is visa card or not
void visa_num(long card_number)
{
    int check_sum(int card_number);
    int check = check_sum(card_number);
    int card_number_len = log10(card_number) + 1;
    int first;
    // checking first digit of number as VISA cards start with 4
    while (card_number >= 10)
    {
        card_number = card_number / 10;
    }
    first = card_number;
    printf("first digit: %i \n", first);
    // loop to validate visa card criteria
    if ((card_number_len == 13 || card_number_len == 16) && (check == 0 && first == 4))
    {
        printf("VISA\n");
    }
    else
    {
        printf("NOT A VISA CARD\n");
    }
}
// function to verify whether the number is american express card or not
void american_num(long card_number)
{
    int check_sum(int card_number);
    int check = check_sum(card_number);
    int card_number_len = log10(card_number) + 1;
    int first_two;
    // checking first two digits of number as American express cards start with 34 or 37
    while (card_number >= 100)
    {
        card_number = card_number / 10;
    }

    first_two = card_number;
    printf("first two digits: %i \n", first_two);

    // condition to validate the american express criteria
    if (card_number_len == 15 && check == 0 && (first_two == 34 || first_two == 37))
    {
        printf("American Express\n");
    }
    else
    {
        printf("NOT A AMERICAN EXPRESS CARD\n");
    }
}

// function to verify whether the number is master card or not
void master_num(long card_number)
{
    int check_sum(int card_number);
    int check = check_sum(card_number);
    int card_number_len = log10(card_number) + 1;
    int first_two;
    // checking first two digits of number as MASTER cards start with 51,52,53,54 or 55
    while (card_number >= 100)
    {
        card_number = card_number / 10;
    }

    first_two = card_number;
    printf("first two digits: %i \n", first_two);

    if (card_number_len == 16 && check == 0 &&
        (first_two == 51 || first_two == 52 || first_two == 53 || first_two == 54 || first_two == 55))
    {
        printf("Master Card\n");
    }
    else
    {
        printf("NOT A MASTER CARD\n");
    }
}

// check sum function to calculate the check sum of entered number
int check_sum(int card_number)
{
    int alt_digits[] = {};
    int count = 0;
    int sum = 0;
    bool doubleDigit = false;
    // retrieving card number and storing in alt_digits
    while (card_number > 0)
    {
        alt_digits[count++] = card_number % 10;
        card_number = card_number / 10;
    }

    // using alt_digits array and loop to multiply each element by 2 and than adding them together
    for (int i = count - 1; i >= 0; i--)
    {
        int digit = alt_digits[i];
        if (doubleDigit)
        {
            digit = digit * 2;
            if (digit > 9)
            {
                digit = digit % 10 + 1;
            }
        }
        sum += digit;
        doubleDigit = !doubleDigit;
    }

    return sum % 10;
}