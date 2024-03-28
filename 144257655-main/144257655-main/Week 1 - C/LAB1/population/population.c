#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start_size, end_size;
    do
    {
        start_size = get_int("Start size: ");
    }
    while (start_size < 9);
    // TODO: Prompt for end size
    do
    {
        end_size = get_int("End size: ");
    }
    while (end_size < start_size);
    // TODO: Calculate number of years until we reach threshold
    int years = 0;
    double born;
    double pass_away;
    while (start_size < end_size)
    {
        born = start_size / 3;
        pass_away = start_size / 4;
        start_size = start_size + born - pass_away;
        years++;
    }
    // TODO: Print number of years
    printf("Years: %i\n", years);
}
