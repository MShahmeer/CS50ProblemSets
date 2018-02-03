#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Check of only one argument is present
    if (argc == 2)
    {
        // Convert char argument to integer
        int k = atoi(argv[1]);
        printf("%i\n", k);
        // Get plaintext as input
        string plaintext = get_string("plaintext: ");
        string ciphertext = plaintext;
        // Iterate over characters in plaintext string
        for (int i = 0, n = strlen(plaintext); i < n; i++)
        {
            // Set character as variable
            char character = plaintext[i];
            // Checks if character is alphabet
            if (isalpha(character))
            {
                // Check if character uppercase or lowercase
                if (character >= 'A' && character <= 'Z')
                {
                    // Encipher character
                    character = character - 'A';
                    character = (character + k) % 26;
                    character = character + 'A';
                }
                else
                {
                    // Encipher character
                    character = character - 'a';
                    character = (character + k) % 26;
                    character = character + 'a';
                }

                // Changes character to enciphered char
                ciphertext[i] = character;
                //printf("%s\n", ciphertext);
            }
            else
            {
                // Skips over non-alpha character without modifying
                ciphertext[i] = character;
                //printf("%s\n", ciphertext);
            }
        }
        printf("ciphertext: %s\n", ciphertext);
    }
    // Print message if less than or more than one argument is present
    else
    {
        printf("Usage: ./caesar k");
        return 1;
    }
}