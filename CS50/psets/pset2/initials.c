#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string name = "";
    name = GetString();
    
    for (int i = 0, n = strlen(name); i < n; i++)
    {
        if (i == 0)
        {
            printf("%c", toupper(name[i]));
        }
        else if (name[i] == 32)
        {
            printf("%c", toupper(name[i+1]));
        }
    }
    printf("\n");
}
