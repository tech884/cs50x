/**
 Name: caesar.c
 
 Eric L
 
 Get user's secret key from command line,
 user then enters a words and then
 outputs the first initials of the entered name (i.e. first, middle, last).
*/

#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[ ] )
{

    // Get secret key (non-negative integer) from command line
    string key = argv[1];

    if (argc != 2)
    {
        printf("Please provide a valid key (non-negative integer).\n");
        return 1;
    }
    else
    {
        // Convert the secret key (string) to an integer
        int intKey = atoi (key) % 26;
        
        // Check that secret key is valid, not 0 which equates to no encryption 
        if (intKey == 0)
        {
            printf("Invalid key. Try again.\n");
            return 1;
        }
    
        // Get the plaintext to be encrypted
        string plainText = GetString();
        if (plainText != NULL)
        {
            int length = strlen (plainText);

            // iterate over entire array of plainText characters
            for (int i = 0; i < length; i++)
            {
        
                // Check if plaintext is uppercase or lowercase
                // Switch character to ascii number and encrypt, printing back characters
                if (isupper (plainText [i] ))
                {
                    int cipherText = ((plainText[i] - 65 + intKey) % 26) + 65;
                    printf("%c", (char) cipherText);
                }
                else if (islower (plainText [i] ))
                {
                    int cipherText = ((plainText[i] - 97 + intKey) % 26) + 97;
                    printf("%c", (char) cipherText);
                }
                else
                {
                    // Print back non-alphabetical characters unencrypted
                    printf("%c", (char) plainText[i]);
                }
            }
            printf("\n");
            return 0;
        }
    }
}
