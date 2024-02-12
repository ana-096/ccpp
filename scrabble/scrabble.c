#include <stdio.h>
#include <string.h>

size_t POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

size_t computer_score(char word[])
{
    size_t score = 0;

    for (size_t i = 0; i < strlen(word); i++)
    {
        if (word[i] >= 'A' && word[i] <= 'Z')
        {
            score += POINTS[word[i] - 'A'];
        }
        else if (word[i] >= 'a' && word[i] <= 'z')
        {
            score += POINTS[word[i] - 'a'];
        }
    }

    return score;
}

int main(int argc, char **argv)
{
    char word1[51];
    size_t score1;
    char word2[51];
    size_t score2;

    printf("Player 1: ");
    fgets(word1, sizeof(word1), stdin);

    printf("Player 2: ");
    fgets(word2, sizeof(word2), stdin);

    score1 = computer_score(word1);
    score2 = computer_score(word2);

    if (!score1 || !score2)
        return -1;

    if (score1 == score2)
    {
        printf("Tie!");
    }
    else
    {
        printf("%s", (score1 > score2) ? "Player 1 wins!" : "Player 2 wins!");
    }

    return 0;
}
