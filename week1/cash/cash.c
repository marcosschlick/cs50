#include <cs50.h>
#include <stdio.h>

int get_quarters(int owed);
int get_dimes(int owed);
int get_nickels(int owed);
int get_pennies(int owed);

int main(void)
{
    int change_owed = 0;

    do
    {
        change_owed = get_int("Change owed: ");
    }
    while (change_owed <= 0);

    int quarters = get_quarters(change_owed);
    change_owed -= 25 * quarters;

    int dimes = get_dimes(change_owed);
    change_owed -= 10 * dimes;

    int nickels = get_nickels(change_owed);
    change_owed -= 5 * nickels;

    int pennies = get_pennies(change_owed);

    int coins = quarters + dimes + nickels + pennies;
    printf("%i\n", coins);
}

int get_quarters(int owed)
{
    int coins = 0;
    while (owed >= 25)
    {
        coins += 1;
        owed -= 25;
    }
    return coins;
}

int get_dimes(int owed)
{
    int coins = 0;
    while (owed >= 10)
    {
        coins += 1;
        owed -= 10;
    }
    return coins;
}

int get_nickels(int owed)
{
    int coins = 0;
    while (owed >= 5)
    {
        coins += 1;
        owed -= 5;
    }
    return coins;
}

int get_pennies(int owed)
{
    int coins = 0;
    while (owed >= 1)
    {
        coins += 1;
        owed -= 1;
    }
    return coins;
}

