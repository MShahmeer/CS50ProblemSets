#define _XOPEN_SOURCE
#define _GNU_SOURCE

#include <crypt.h>
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, string argv[])
{
    // Check if only one argument is present
    if (argc == 2)
    {
        // Set value of hash
        string hash = argv[1];

        // Declare salt variable
        char salt[3];

        // Set value of salt from first two digits of hash to salt variable
        for (int i = 0; i < 2; i++)
        {
            salt[i] = hash[i];
        }

        // Declare variable to store generated passwords
        char password[6];

        // Iterate over first letter
        for (int i = 0; i <= 122; i++)
        {
            if (isalpha(i))
            {
                // Iterate over second letter
                for (int j = 0; j <= 122; j++)
                {
                    if (j == 0 || isalpha(j))
                    {
                        // Iterate over third letter
                        for (int k = 0; k <= 122; k++)
                        {
                            if (k == 0 || isalpha(k))
                            {
                                // Iterate over fourth letter
                                for (int l = 0; l <= 122; l++)
                                {
                                    if (l == 0 || isalpha(l))
                                    {
                                        // Iterate over fifth and final letter
                                        for (int m = 0; m <= 122; m++)
                                        {
                                            if (m == 0 || isalpha(m))
                                            {
                                                // Set characters to password
                                                password[0] = i;
                                                password[1] = j;
                                                password[2] = k;
                                                password[3] = l;
                                                password[4] = m;
                                                password[5] = '\0';

                                                // Generate hash and check if it matches input hash
                                                if (strcmp(crypt(password, salt), hash) == 0)
                                                {
                                                    goto ENDPOINT;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

ENDPOINT:
        printf("%s\n", password);
    }
    // Print message if less than or more than one argument is present
    else
    {
        printf("Enter only one hashed password as an argument");
        return 1;
    }
}