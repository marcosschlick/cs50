#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

string get_ciphertext(string text, int key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s\n", argv[0]);
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (isalpha(argv[1][i]))
        {
            printf("Usage: %s\n", argv[0]);
            return 1;
        }
    }

    int key = atoi(argv[1]);
    key %= 26;

    string plaintext = get_string("plaintext: ");
    string ciphertext = get_ciphertext(plaintext, key);

    printf("ciphertext: %s\n", ciphertext);
}

string get_ciphertext(string text, int key)
{
    string ciphertext = text;
    for (int i = 0; i < strlen(ciphertext); i++)
    {
        char c = ciphertext[i];
        if (isalpha(c))
        {
            int ascii = (int) c;
            ascii += key;
            if (islower(c))
            {
                if (ascii > 122)
                {
                    ascii -= 26;
                }
            }
            else
            {
                if (ascii > 90)
                {
                    ascii -= 26;
                }
            }
            ciphertext[i] = (char) ascii;
        }
        else
        {
            ciphertext[i] = c;
        }
    }
    return ciphertext;
}

