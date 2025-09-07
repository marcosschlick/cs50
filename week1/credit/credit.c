#include <cs50.h>
#include <stdio.h>

bool is_valid(long card_number);
string get_card_type(long card_number);
int count_digits(long card_number);
long power_of_ten(int exponent);

int main(void)
{

    long card_number = 0;
    do
    {
        card_number = get_long("Number: ");
    }
    while (card_number == 0);

    if (is_valid(card_number))
    {
        printf("%s\n", get_card_type(card_number));
    }
    else
    {
        printf("INVALID\n");
    }
}

int count_digits(long card_number)
{
    int digit_count = 0;
    while (card_number > 0)
    {
        card_number /= 10;

        digit_count++;
    }
    return digit_count;
}

bool is_valid(long card_number)
{
    int non_multiplied_digits = 0;
    int multiplied_digits = 0;
    bool alternate = false;

    while (card_number > 0)
    {
        int digit = card_number % 10;
        card_number /= 10;

        if (!alternate)
        {
            non_multiplied_digits += digit;
            alternate = true;
        }
        else
        {
            int product = digit * 2;
            multiplied_digits += product % 10;
            product /= 10;
            multiplied_digits += product;
            alternate = false;
        }
    }

    int sum_total = non_multiplied_digits + multiplied_digits;

    if (sum_total % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

string get_card_type(long card_number)
{
    int digit_count = count_digits(card_number);

    if (digit_count == 13)
    {
        int first_digit = card_number / power_of_ten(12);
        if (first_digit == 4)
        {
            return "VISA";
        }
        else
        {
            return "INVALID";
        }
    }
    else if (digit_count == 15)
    {
        int first_two_digits = card_number / power_of_ten(13);
        if (first_two_digits == 34 || first_two_digits == 37)
        {
            return "AMEX";
        }
        else
        {
            return "INVALID";
        }
    }
    else if (digit_count == 16)
    {
        int first_digit = card_number / power_of_ten(15);
        int first_two_digits = card_number / power_of_ten(14);
        if (first_digit == 4)
        {
            return "VISA";
        }
        else if (first_two_digits > 50 && first_two_digits < 56)
        {
            return "MASTERCARD";
        }
        else
        {
            return "INVALID";
        }
    }
    else
    {
        return "INVALID";
    }
}

long power_of_ten(int exponent)
{
    long result = 1;
    for (int i = 0; i < exponent; i++)
    {
        result *= 10;
    }
    return result;
}

