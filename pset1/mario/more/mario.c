#include <stdio.h>
#include <cs50.h>

// Defining prototypes
void print_spaces(int spaces);
void print_hashes(int hashes);

int main(void)
{
    // Prompt user for height and keep repeating if negative numbers or numbers greater than 23 are entered
    int height = -1;
    while (height < 0 || height > 23)
    {
        height = get_int("Height: ");
    }

    // Iterate through various layers
    for (int layer = 1; layer <= height; layer++)
    {
        // Calculate number of spaces
        int spaces = height - layer;
        // Print Spaces and Hashes, mirror and print new line
        print_spaces(spaces);
        print_hashes(layer);
        printf("  ");
        print_hashes(layer);
        printf("\n");
    }
}

// Print specific number of spaces
void print_spaces(int spaces)
{
    for (int i = 0; i < spaces; i++)
    {
        printf(" ");
    }
}

// Print specific number of hashes
void print_hashes(int hashes)
{
    for (int i = 0; i < hashes; i++)
    {
        printf("#");
    }
}