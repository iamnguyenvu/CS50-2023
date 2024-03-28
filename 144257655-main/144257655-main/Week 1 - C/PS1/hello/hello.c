#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("What's your name? ");
    // string address = get_string("Where's your address? ");
    printf("hello, %s\n", name);
}