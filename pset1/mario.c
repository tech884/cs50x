#include <stdio.h>
#include <cs50.h>

int main()
{
    int height; 
    do
    {
    // prompt user for height
    printf("What height would you like for your half-pyramid?: ");
    height = GetInt();
    }
    while (height < 0 || height > 23);
    
    char space = ' ';
    char hash = '#';
    int num_of_spaces;
    
    // set number of spaces to print on each row to 1 less than height requested
    num_of_spaces = height - 1;
    
    for (int row = 1; row <= height; row++)
    {
        // 1st column type for printing spaces
        for (int column_type_1 = 1; column_type_1 <= num_of_spaces; column_type_1++)
        {
            printf("%c", space);
        }
        
        // decrease number of spaces by 1
        num_of_spaces--;
        
        // 2nd column type for printing hashes
        for (int column_type_2 = 1; column_type_2 <= row; column_type_2++)
        {
            printf("%c", hash);
        }
        
        // 3rd column type for adding 1 hash at end of row
        printf("%c", hash);
        // goto next row
        printf("\n");
    }
    return 0;
}
