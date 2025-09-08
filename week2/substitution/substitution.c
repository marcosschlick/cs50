#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
bool has_invalid_or_duplicate_characters(string text);
string get_ciphertext(string text, int diffs[]);
int get_diffs(string key, int i);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    bool invalid_characters = has_invalid_or_duplicate_characters(argv[1]);

    if (invalid_characters)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    int letters = count_letters(argv[1]);

    if (letters != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    string key = argv[1];
    int diffs[26];

    for (int i = 0; i < strlen(key); i++)
    {
        diffs[i] = get_diffs(key, i);
    }

    string plaintext = get_string("plaintext: ");
    string ciphertext = get_ciphertext(plaintext, diffs);
    printf("ciphertext: %s\n", ciphertext);

    return 0;
}

int count_letters(string text)
{
    int letters = 0;
    while (text[letters] != '\0' || isalpha(text[letters]))
    {
        letters++;
    }
    return letters;
}

bool has_invalid_or_duplicate_characters(string text)
{
    bool invalid = false;
    char duplicate[26];
    for (int i = 0; i < strlen(text); i++)
    {
        duplicate[i] = tolower(text[i]);
        if (!isalpha(text[i]))
        {
            invalid = true;
            return invalid;
        }
        for (int j = 0; j < i; j++)
        {
            if (duplicate[j] == tolower(text[i]))
            {
                invalid = true;
                return invalid;
            }
        }
    }
    return invalid;
}

string get_ciphertext(string text, int diffs[])
{
    string ciphertext = text;
    for (int i = 0; i < strlen(ciphertext); i++)
    {
        if (isalpha(ciphertext[i]))
        {
            int pos = (int) ciphertext[i];
            if (isupper(ciphertext[i]))
            {
                pos -= 65;
            }
            else
            {
                pos -= 97;
            }
            ciphertext[i] += diffs[pos];
        }
    }
    return ciphertext;
}

int get_diffs(string key, int i)
{
    int pos = i;
    int diff = 0;
    if (isupper(key[i]))
    {
        pos += 65;
        diff = (int) key[i] - pos;
        return diff;
    }
    else
    {
        pos += 97;
        diff = (int) key[i] - pos;
        return diff;
    }
}

