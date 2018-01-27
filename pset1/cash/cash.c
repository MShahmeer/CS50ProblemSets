#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // Ask for input and validate that it's positive
    int change = -1;
    while (change < 0)
    {
        change = (int)(roundf(get_float("Change due: ") * 100));
    }

    // Define variables
    int remaining_change = change;
    int coins_needed = 0;

    // Iterate over change and remove remainder while incrementing coins needed
    while (remaining_change > 0)
    {
        // For quarters
        if (remaining_change >= 25)
        {
            remaining_change = remaining_change - 25;
            coins_needed = coins_needed + 1;
        }
        // For dimes
        else if (remaining_change >= 10)
        {
            remaining_change = remaining_change - 10;
            coins_needed = coins_needed + 1;
        }
        // For nickels
        else if (remaining_change >= 5)
        {
            remaining_change = remaining_change - 5;
            coins_needed = coins_needed + 1;
        }
        // For pennies
        else
        {
            remaining_change = remaining_change - 1;
            coins_needed = coins_needed + 1;
        }
    }

    // Output number of coins needed
    printf("%i\n", coins_needed);
}