#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int only_digits(string s);
char rotate(char i, int key);

int main(int argc, string argv[])
{
    if (argc == 2 && only_digits(argv[1]))
    {
        string p = get_string("String to rotate: ");
        int len = strlen(p);
        //encryptor
        int key = atoi(argv[1]);
        // printf("key: %s: %i\n", argv[1], key);
        if (key > 26)
        {
            key = key % 26;
        }
        printf("ciphertext: ");
        for (int i = 0; i < len; i++)
        {
            char c = rotate(p[i], key);
            // printf("%c : %i : %c\n", p[i], c, c);
            printf("%c", c);
        }
        printf("\n");
        return 0;
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1; //i.e error
    }
}

int only_digits(string s)
{
    int len = strlen(s);
    int r;
    //loop through cmd line arg and determine if all chars are digits
    for (int i = 0; i < len; i++)
    {
        if (!isdigit(s[i]))
        {
            r = 0;
        }
        else
        {
            r = 1;
        }
    }
    return r;
}

char rotate(char i, int key)
{
    char c;
    if (isalpha(i))
    {
        c = key + i;
        //for lowercase letters
        if (islower(i))
        {
            if (c > 122) //works for upto 127
            {
                c = 97 + (c - 122 - 1);
            }
            else if (c < 0) //for c > 127 i.e -128 downwards
            {
                //s = -128, t = -127 and u = -126 etc
                c = 97 + (-1 * (-i - key) - 123);
                // printf("k: %i\n", k);
            }
        }
        //for uppercase...
        else if (isupper(i))
        {
            if (c > 90) //works for upto 127
            {
                c = 65 + (c - 90 - 1);
            }
            // else if (c < 0) //for c > 127 i.e -128 downwards
            // {
            //     //s = -128, t = -127 and u = -126 etc
            //     c = 97 + (-1 * (-p[i] - key) - 123);
            //     // printf("k: %i\n", k);
            // }
        }
    }
    else
    {
        c = i;
    }

    return c;
}