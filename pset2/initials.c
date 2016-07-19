#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    // get name from user
    string name = GetString();
    // print first character of name as uppercase
    printf("%c", toupper (name [0]));
    
    // declare space & length of string
    char space = ' ';
    int length = strlen (name);
    
    // iterate over entire array of name characters
    for (int i = 0; i < length; i++)
    {
        // execute only when character is a space
        while (name [i] == space)
        {
            printf("%c", toupper (name [i + 1]));
            i++;
        }
    }
    printf("\n");
}
