#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int get_word_points(string word);

const int POINTS[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                      1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");

    int player1_points = get_word_points(player1);
    int player2_points = get_word_points(player2);

    if (player1_points > player2_points)
    {
        printf("Player 1 wins\n");
    }
    else if (player1_points < player2_points)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int get_word_points(string word)
{
    int points = 0;

    for (int i = 0; i < strlen(word); i++)
    {
        if (isalpha(word[i]))
        {
            char c = toupper(word[i]);
            int ascii = (int) c;
            int position = ascii - 65;
            points += POINTS[position];
        }
    }

    return points;
}

