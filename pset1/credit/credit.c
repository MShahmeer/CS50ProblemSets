#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //378282246310005
    // Get card number
    long long card_number = get_long_long("Enter card number: ");
    long long card_number_to_be_iterated = card_number;

    int number_of_digits = 0;

    // Define checksum constituents
    int sum_of_digits_multiplied_by_two = 0;
    int sum_of_digits_not_multiplied_by_two = 0;

    // Iterate over card digits from right to left
    for (int i = 1; card_number_to_be_iterated > 0; i++)
    {
        // Get digit
        int digit = card_number_to_be_iterated % 10;
        // Move to next place
        card_number_to_be_iterated = card_number_to_be_iterated / 10;

        // Check if digit needs to be multiplied by two or not
        if (i % 2 == 1)
        {
            // Add to checksum constituent for digits which don't need to be multiplied by two
            sum_of_digits_not_multiplied_by_two = sum_of_digits_not_multiplied_by_two + digit;
        }
        else
        {
            digit = digit * 2;
            // Check if only one digit or two
            if (digit / 10 == 0)
            {
                sum_of_digits_multiplied_by_two = sum_of_digits_multiplied_by_two + digit;
            }
            else
            {
                // Add sum of digits together
                int digit_sum = (digit % 10) + ((digit / 10 ) % 10);
                sum_of_digits_multiplied_by_two = sum_of_digits_multiplied_by_two + digit_sum;
            }
        }
        number_of_digits = i;
    }

    // Create final checksum value
    int checksum = sum_of_digits_multiplied_by_two + sum_of_digits_not_multiplied_by_two;

    // Check if last digit of checksum is 0
    if (checksum % 10 == 0)
    {
        // Check for number of digits to calssify card type
        switch (number_of_digits)
        {
            // AMEX card has 15 digits
            case 15:
                printf("AMEX\n");
                break;
            // VISA card has 13 or 16 digits
            case 13:
                printf("VISA\n");
                break;
            // Checking rightmost digit
            case 16:
                if ((card_number / 1000000000000000) % 10 == 4)
                {
                    // VISA card starts with 4
                    printf("VISA\n");
                }
                else
                {
                    // MASTERCARD starts with 51...55
                    printf("MASTERCARD\n");
                }
                break;
        }
    }
    else
    {
        printf("INVALID\n");
    }
}