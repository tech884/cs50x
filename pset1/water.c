/**
 Name: water.c
 
 Eric L
 
 Takes user input of shower length and outputs equivalent volume of water bottles.
*/

#include <stdio.h>
#include <cs50.h>

int main()
{
    // prompt user for shower length
    printf("How long is your shower to the nearest whole minute?: ");
    int shower_length = GetInt();
    
    // convert shower length to number of water bottles
    int num_of_bottles = 12 * shower_length;
    
    printf("That's equivalent to the following number of 16-oz water bottles: %i\n", num_of_bottles);
}
