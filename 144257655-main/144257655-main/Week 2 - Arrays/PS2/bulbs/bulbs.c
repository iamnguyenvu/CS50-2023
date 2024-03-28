#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // TODO
    string bulb = get_string("Message: ");
    for (int i = 0; i < strlen(bulb); i++)
    {
        int repre = (int) bulb[i];
        int temp = repre;
        int arr[] = {0, 0, 0, 0, 0, 0, 0, 0};
        int bit;

        while (temp > 0)
        {
            for (int j = 7; j >= 0; j--)
            {
                bit = temp % 2;
                arr[j] = bit;
                temp /= 2;
            }
        }
        for (int h = 0; h < 8; h++)
        {
            print_bulb(arr[h]);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}