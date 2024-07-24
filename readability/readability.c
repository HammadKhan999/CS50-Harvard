#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Forwad declaration fo functions used
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int calculate_grade(int letters, int words, int sentences);

// Main function
int main(void)
{
    // declaring variables to count letters, words, sentences, and grade
    int letters = 0;
    int words = 0;
    int sentences = 0;
    int grade = 0;
    // getting string as input from user
    string text = get_string("Enter Text: ");
    // calling required functions to calculate number of letters, words and sentences in string
    letters = count_letters(text);
    words = count_words(text);
    sentences = count_sentences(text);
    // calculating grade using calculate_grade function
    grade = calculate_grade(letters, words, sentences);
    // using if-else loop to meet the requirements of check50
    if (grade < 0)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

// function definition to return number of letters in string
int count_letters(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i <= n; i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            count++;
        }
    }
    return count;
}
// function definition to return number of words in string
int count_words(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i <= n; i++)
    {
        // using isspace built-in function of ctype.h to check for spaces
        if (isspace(text[i]))
        {
            count++;
        }
    }
    count++;
    return count;
}

// function definition to return number of sentences in string
int count_sentences(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i <= n; i++)
    {
        // if loop to count words as per instrcution of problem set by counting only those ending with ., ?, ! as sentence
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            count++;
        }
    }
    return count;
}

// function to calculate grade using letters words, and sentences of string
int calculate_grade(int letters, int words, int sentences)
{

    // using Coleman-Liau index formula to calculate grade
    float L = ((float) letters / words) * 100;
    float S = ((float) sentences / words) * 100;

    float index = (0.0588 * L) - (0.296 * S) - 15.8;
    index = round(index);
    return index;
}
