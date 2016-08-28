#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int alphabet_pos(char a);
bool is_letter(string b);

int main(int argc, string argv[])
{
    string phrase;
    string keyword = argv[1];
    
    if (argc != 2 || is_letter(keyword) == false)
    {
        printf("You must supply an alpha only keyword. Try again\n");
        return 1;
    }
    else
    {
        int cypher_len = strlen(keyword);
        int cypher_pos = 0;
        phrase = GetString();
        char cyphered_word[strlen(phrase) + 1];
        cyphered_word[strlen(phrase)] = '\0';
        
        for (int i = 0, n = strlen(phrase); i < n; i++)
        {
            if (isalpha(phrase[i]))
            {
                if (isupper(phrase[i]))
                {
                    if (phrase[i] + alphabet_pos(keyword[cypher_pos % cypher_len]) > 90)
                    {
                        cyphered_word[i] = (65 + alphabet_pos(keyword[cypher_pos % cypher_len]) - (91 - phrase[i]));
                        cypher_pos++;
                    }
                    else
                    {
                        cyphered_word[i] = (phrase[i] + alphabet_pos(keyword[cypher_pos % cypher_len]));
                        cypher_pos++;
                    }
                }
                else
                {
                    if (phrase[i] + alphabet_pos(keyword[cypher_pos % cypher_len]) > 122)
                    {
                        cyphered_word[i] = (97 + alphabet_pos(keyword[cypher_pos % cypher_len]) - (123 - phrase[i]));
                        cypher_pos++;
                    }
                    else
                    {
                        cyphered_word[i] = (phrase[i] + alphabet_pos(keyword[cypher_pos % cypher_len]));
                        cypher_pos++;
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

/* Function to return the number of characters to move a letter forward.
The function takes one argument, a letter, and returns it's position in the alphabet
irrespective of case ie a or A -> 1, b or B -> 2, ..., z or Z -> 26 */

int alphabet_pos(char a)
{
    char char_upper = toupper(a);
    int pos = char_upper - 65;
    return pos;
}

/* Function to return true or false as to whether a keyword contains anything
other than alpha characters. If it does contain no alpha characters it will
return false otherwise return true */

bool is_letter(string b)
{
    bool flag = true;
    
    for (int i = 0, n = strlen(b); i < n; i++)
    {
        if (isalpha(b[i]) == false)
        {
            flag = false;
        }
    }
    return flag;
}
