from cs50 import get_string


def main():
    # getting string as input from user
    text = get_string("Enter Text: ")
    # using count_letters to calculate number of letters in text
    letters = count_letters(text)

    # using count_words to calculate number of words in text
    words = count_words(text)

    # using count_sentences to calculate number of sentences in text
    sentences = count_sentences(text)

    # calculating grade using calculate_grade function
    grade = calculate_grade(letters, words, sentences)

    # using if-else loop to meet the criteria for grade
    if grade < 0:
        print("Before Grade 1")
    elif grade > 16:
        print("Grade 16+")
    else:
        print("Grade", grade)


# function to return number of letters in string
def count_letters(text):
    count = 0
    for i in range(len(text)):
        if (text[i] >= "a" and text[i] <= "z") or (text[i] >= "A" and text[i] <= "Z"):
            count += 1

    return count


# function to return number of words in string
def count_words(text):
    count = 1
    for i in range(len(text)):
        if text[i] == " ":
            count += 1
    return count


# function to return number of sentences in string
def count_sentences(text):
    count = 0
    for i in range(len(text)):
        if text[i] == "." or text[i] == "?" or text[i] == "!":
            count += 1
    return count


# function to calculate grade using letters words, and sentences of text
def calculate_grade(letters, words, sentences):
    # using Coleman-Liau index formula to calculate grade
    L = (letters / words) * 100
    S = (sentences / words) * 100

    index = round(((0.0588 * L) - (0.296 * S) - 15.8))
    return index


main()
