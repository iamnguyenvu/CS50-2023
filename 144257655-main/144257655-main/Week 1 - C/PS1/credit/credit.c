#include <cs50.h>
#include <stdbool.h>
#include <stdio.h>

long get_credit();
bool check_credit(long credit);
void display(long credit, bool is_valid);

int main(void)
{
    long credit = get_credit();
    bool is_valid = check_credit(credit);
    display(credit, is_valid);
}

long get_credit()
{
    long credit;
    do
    {
        credit = get_long("Number: ");
    }
    while (credit < 1);
    return credit;
}

bool check_credit(long credit)
{
    long temp = credit;
    int sum = 0, mod1, mod2;

    while (temp > 0)
    {
        mod1 = temp % 10;
        sum += mod1;
        temp /= 100;
    }

    temp = credit / 10;
    long two_times;

    while (temp > 0)
    {
        mod2 = temp % 10;
        two_times = 2 * mod2;
        sum += ((two_times % 10) + (two_times / 10));
        temp /= 100;
    }

    return (sum % 10 == 0);
}

void display(long credit, bool is_valid)
{
    long temp = credit;
    long length = 0;
    long divisor = 10;
    int fisrt_digit;
    long two_fisrtdigit = credit;
    
    if (is_valid)
    {
        while (temp > 0)
        {
            temp /= 10;
            length++;
        }

        while (two_fisrtdigit > 100)
        {
            two_fisrtdigit /= 10;
        }

        temp = credit;
        fisrt_digit = two_fisrtdigit / 10;

        if ((length == 16) && (two_fisrtdigit >= 51 && two_fisrtdigit < 56))
        {
            printf("MASTERCARD\n");
        }
        else if ((length == 15) && (two_fisrtdigit == 34 || two_fisrtdigit == 37))
        {
            printf("AMEX\n");
        }
        else if ((length == 13 || length == 16) && (fisrt_digit == 4))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}