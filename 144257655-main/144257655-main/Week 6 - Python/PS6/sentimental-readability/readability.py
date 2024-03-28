# TODO

from cs50 import get_string


def main():
    text = get_string("Text: ")

    letter = count_letters(text)
    word = count_words(text)
    sentence = count_sentences(text)

    reading_level = calculator(letter, word, sentence)
    if reading_level > 16:
        print("Grade 16+")
    elif reading_level < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {round(reading_level)}")


def calculator(letter, word, sentence):
    L = float(letter / word * 100.0)
    S = float(sentence / word * 100.0)
    index = float(0.0588 * L - 0.296 * S - 15.8)
    return float(index)


def count_letters(text):
    count = 0
    for char in text:
        if char.isalpha():
            count += 1
    return count


def count_words(text):
    count = 0
    for char in text:
        if char == " ":
            count += 1
    if count > 0:
        count += 1
    return count


def count_sentences(text):
    count = 0
    count += text.count("!")
    count += text.count(".")
    count += text.count("?")
    return count


main()
