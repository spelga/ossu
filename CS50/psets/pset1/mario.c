#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    do
    {
        printf("Height: ");
        height = GetInt();
    }
    while (height < 0 || height > 23);
    
    // loop until the height specified by the user is reached
    for (int i = 0; i < height; i++)
    {
        // set number of spaces for each row of the pyramid
        for (int j = height - 1; i < j; j--)
        {
            printf(" ");
        }
        
        // set number of hashes for each row of the pyrmaid
        for (int k = 0; k < i + 2; k++)
        {
            printf("#");
        }
        
        // take a new line at row end
        printf("\n");
    }
}