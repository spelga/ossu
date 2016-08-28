#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int quarters = 25;
    int dimes = 10;
    int nickles = 5;
    float f_change = 0;
    int change = 0;
    int num_coins = 0;
    
    do
    {
        printf("O hai! How much change is owed?\n");
        f_change = GetFloat();
    }
    while (f_change <= 0);
    
    change = round((f_change * 100));
    
    // calculate quarters that can be used
    num_coins += (change / quarters);
    change %= quarters;
    
    // calculate dimes that can be used
    num_coins += (change / dimes);
    change %= dimes;
    
    // calculate nickles that can be used
    num_coins += (change / nickles);
    change %= nickles;
    
    // calulate pennies that can be used
    num_coins += change;
    
    printf("%i\n", num_coins);
    
}