#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_key_char_value(char key_char);

int main(int argc, string argv[])
{
    // Check if only one argument is present
    if (argc == 2)
    {
        // Validate if k is alpha
        string k = argv[1];
        bool is_k_alpha;
        for (int i = 0, n = strlen(k); i < n; i++)
        {
            if (isalpha(k[i]))
            {
                is_k_alpha = true;
            }
            else
            {
                is_k_alpha = false;
                break;
            }
        }

        if (is_k_alpha)
        {
            // Get plaintext as input
            string plaintext = get_string("plaintext: ");
            string ciphertext = plaintext;

            // Iterate over characters in plaintext string
            for (int i = 0, j = 0, n = strlen(plaintext); i < n; i++)
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
                        character = (character + get_key_char_value(k[j % strlen(k)])) % 26;
                        character = character + 'A';
                    }
                    else
                    {
                        // Encipher character
                        character = character - 'a';
                        character = (character + get_key_char_value(k[j % strlen(k)])) % 26;
                        character = character + 'a';
                    }

                    // Changes character to enciphered char
                    ciphertext[i] = character;
                    // Only increment counter if character is alphabet
                    j = j + 1;
                }
                else
                {
                    // Skips over non-alpha character without modifying
                    ciphertext[i] = character;
                }
            }
            printf("ciphertext: %s\n", ciphertext);
            return 0;
        }
        // Print message if k not alphabetical
        else
        {
            printf("Usage: ./vigenere k");
            return 1;
        }
    }
    // Print message if less than or more than one argument is present
    else
    {
        printf("Usage: ./vigenere k");
        return 1;
    }
}

// Function to get the value of character in cipher
int get_key_char_value(char key_char)
{
    if (isupper(key_char))
    {
        return key_char - 'A';
    }
    else
    {
        return key_char - 'a';
    }
}