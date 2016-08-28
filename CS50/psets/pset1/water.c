#include <stdio.h>
#include <cs50.h>



int main(void)
{
    int minutes;
    int bottles;
    
    do
    {
        printf("minutes: ");
        minutes = GetInt();
    }
    while (minutes < 1);
    bottles = minutes * 12;
    printf("bottles: %i\n", bottles);
}