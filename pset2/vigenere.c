/*
  Name: vigenere.c
  
  Eric L

  Get user's alphabetic keyword (only contains characters A-Z or a-z) from command line,
  user then enters original text,
  Vigenere cipher uses keyword to encrypt original text with the keyword, and then
  outputs ciphered text.
*/

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[ ])
{
	  // Get keyword from command line
    string keyword = argv[1];
 
    if (argc != 2)
    {
        printf("Please provide a valid keyword.\n");
        return 1;
    }

	  int kwLength = strlen(keyword);

	  // Checks that keyword is alphabetic
    for (int i = 0; i < kwLength; i++)
    {
        
        if (isalpha(keyword[i]) == 0)
        {
    	    printf("Invalid. Key must be only alphabetic. Please try again.\n");
        	return 1;
		    }
    }
    
    int cipherText;
    int keywordIndex;
 
    // Get plain text to be encrypted
    string plainText = GetString();
    int ptLength = strlen(plainText);
    
    // Iterate over entire array of plainText characters
    for (int j = 0, k = 0; j < ptLength; j++, k++)
    {
        // Reuse keyword when shorter than plain text
        if (k >= strlen(keyword))
        {
            k = 0;
        }

        keywordIndex = keyword[k]; 
 
        // Do not apply keyword when plainText[i] is non-alphabetic
        if (isalpha(plainText[j]) == 0)
        {
            k = (k - 1);
        }  
 
        // For upper case: 'A' & 'a' --> 0, 'F' & 'f' --> 5, 'Z' & 'z' --> 25
        if ((keywordIndex >= 65) && (keywordIndex <= 90))
        {
            keywordIndex = (keywordIndex - 65);
        }
 
        // For lower case: 'A' & 'a' --> 0, 'F' & 'f' --> 5, 'Z' & 'z' --> 25
        if ((keywordIndex >= 97) && (keywordIndex <= 122))
        {
            keywordIndex = (keywordIndex - 97);
        }
 
        cipherText = (plainText[j] + keywordIndex);
 
        // Wrap after 'Z' for upper case letters
        if (isupper(plainText[j]) && (cipherText > 90))
        {
            cipherText = (cipherText - 26);   
        }
 
        // Wrap after 'z' for lower case letters
        if (islower(plainText[j]) && (cipherText > 122))
        {
            cipherText = (cipherText - 26);
        }
 
        // Print encrypted alphabetic character
        if (isalpha(plainText[j]))
        {
            printf("%c", cipherText);
        }

        // Print back non-alphabetical characters unencrypted   
        else
        {
            printf("%c", plainText[j]);
        }
    }  
    printf("\n");
    return 0;
}
