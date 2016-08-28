#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    string phrase = "";
    
    if (argc != 2) 
    {
        printf("You did not supply the number of characters to shift. Try again!");
        return 1;
    }
    
    else if ((atoi(argv[1]) < 0))
    {
        return 1;
    }
    
    else
    {
        int rot = atoi(argv[1]);
        phrase = GetString();
        char cyphered_word[strlen(phrase) + 1];
        cyphered_word[strlen(phrase)] = '\0';
        for (int i = 0, n = strlen(phrase); i < n; i++)
        {
            if (isalpha(phrase[i]))
            {
                if (isupper(phrase[i]))
                {
                    if (phrase[i] + rot % 26 > 90)
                    {
                        cyphered_word[i] = (65 + (rot % 26 - (91 - phrase[i])));
                    }
                    else
                    {
                        cyphered_word[i] = (phrase[i] + rot % 26);
                    }
                }
                else
                {
                    if (phrase[i] + rot % 26 > 122)
                    {
                        cyphered_word[i] = (97 + (rot % 26 - (123 - phrase[i])));
                    }
                    else
                    {
                        cyphered_word[i] = (phrase[i] + rot % 26);
                    }
                }
            }
            else
            {
                cyphered_word[i] = phrase[i];
            }
        }
    printf("%s\n", cyphered_word);
    }
    
    return 0;
}