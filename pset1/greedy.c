/*
  Name: greedy.c
  
  Eric L
  
  Prompt the user for an amount of money as a float value and then.
  greedy.c will calculate the minumum number of coins needed to achieve that
  amount entered using quarters, dimes, nickels, and pennies.
*/

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main()
{
    float change_requested;
    do
    {
    // prompt user for amount of change requested    
    printf("O hai! How much change is owed?\n");
    // use GetFloat for floating point value
    change_requested = GetFloat();
    }
    while (change_requested < 0);

    int total_cents;
    // typecast to switch change_requested (float) into (integer) cents 
    total_cents = (int) roundf (change_requested * 100);

    int num_of_quarters, num_of_dimes, num_of_nickels, num_of_pennies, total_num_of_coins;
    
    // with total_cents: determine minimum whole quarters, dimes, nickels, pennies owed 
    // max whole quarters removed
    num_of_quarters = total_cents / 25;
    // remainder (cents) after removing whole quarters
    total_cents = total_cents % 25;

    // max whole dimes removed
    num_of_dimes = total_cents / 10;
    // remainder (cents) after removing whole quarters & dimes 
    total_cents = total_cents % 10;

    // max whole nickels removed
    num_of_nickels = total_cents / 5;
    // remainder (cents) after removing whole quarters, dimes & nickels
    total_cents = total_cents % 5;

    // pennies remaining
    num_of_pennies = total_cents;

    total_num_of_coins = num_of_quarters + num_of_dimes + num_of_nickels + num_of_pennies;
    printf("%d\n", total_num_of_coins);

    return 0;
}
