#include <cs50.h>
#include <stdio.h>

void print_blocks(int blocks);
void print_spaces(int spaces);

int main(void)
{
    int height;

    do
    {
        height = get_int("Height: ");
    }
    while (height <= 0);

    for (int i = 0; i < height; i++)
    {
        int spaces = height - i - 1;
        int blocks = i + 1;

        print_spaces(spaces);

        print_blocks(blocks);

        print_spaces(2);

        print_blocks(blocks);

        printf("\n");
    }
}

void print_blocks(int blocks)
{
    for (int i = 0; i < blocks; i++)
    {
        printf("#");
    }
}

void print_spaces(int spaces)
{
    for (int i = 0; i < spaces; i++)
    {
        printf(" ");
    }
}

