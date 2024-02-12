#include <math.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    char text[2048];
    size_t letters = 0;
    size_t words = 1;
    float average_word;
    size_t sentences = 0;
    float average_sentence;
    int index;
    char chr;

    // get input text (big?)
    printf("Text: ");
    fgets(text, sizeof(text), stdin);

    // count letters, words, and sentences

    for (size_t i = 0; i < strlen(text); i++)
    {
        chr = text[i];
        if ((chr >= 'a' && chr <= 'z') || (chr >= 'A' && chr <= 'Z'))
        {
            letters++;
        }
        else if (chr == ' ')
        {
            words++;
        }
        else if (chr == '.' || chr == '?' || chr == '!')
        {
            sentences++;
        }
    }

    // compute index
    // index = 0.0588 * L (average word len) - 0.296 * S (average sentence length) - 15.8
    average_word = (float) letters / (float) words * 100.0f;

    average_sentence = (float) sentences / (float) words * 100.0f;

    index = round(0.0588f * average_word - 0.296f * average_sentence - 15.8f);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index < 16)
    {
        printf("Grade %d\n", index);
    }
    else
    {
        printf("Grade 16+\n");
    }

    return 0;
}
