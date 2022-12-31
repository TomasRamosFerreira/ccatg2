#include <gmp.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "calculatePrimes.c"

/**
 * Authors          => Miguel Berenguer, Pedro Pita and Tomás Ferreira
 * Created At       => 04/01/2023
 * Last Edited At   => 04/01/2023
 * Version          => @v1.0
 *
 * Script that gets all prime numbers up to a limit given by the user
 * And asks the user if he wants to store the result into a file
 * It's using the Sieve of Eratosthenes algorithm.
 * This code was inspired by the folowing site:  https://www.geeksforgeeks.org/sieve-of-eratosthenes/
 */

int main(int argc, char *argv[])
{
    // Declares the variable to store the maximum limit
    mpz_t maxLimit;
    char maxLimitInput[1024];
    unsigned long size;

    // Loop until the user indicates that they want to exit
    char continueExecution;
    do
    {
        // Initialize variable
        mpz_init(maxLimit);

        // Reads the maximum limit from the user input
        printf("Insert the limit: ");
        scanf("%s", maxLimitInput);

        // Parses the maximum limit from the string
        mpz_set_str(maxLimit, maxLimitInput, 10);

        // Calculates the prime numbers
        mpz_t *primes = calculatePrimes(maxLimit, &size);

        // Prints the prime numbers
        gmp_printf("Prime numbers up to %Zd:\n", maxLimit);
        for (unsigned long i = 0; i < size; i++)
            gmp_printf("%Zd\n", primes[i]);

        printf("\n\n");

        // Asks the user if they want to save the prime numbers to a file
        char save_to_file;
        printf("Do you want to save the prime numbers to a file (Y/N)? ");
        scanf(" %c", &save_to_file);

        if (save_to_file == 'Y' || save_to_file == 'y')
        {
            // Asks the user for the file name
            printf("Enter the file name: ");
            char file_name[1024];
            scanf("%s", file_name);

            // Opens the file for writing
            FILE *file = fopen(file_name, "w+");
            if (file == NULL)
            {
                printf("Error opening file!\n");
                return 1;
            }

            // Writes the prime numbers to the file
            for (unsigned long i = 0; i < size; i++)
                gmp_fprintf(file, "%Zd\n", primes[i]);

            // Closes the file
            fclose(file);

            printf("Prime numbers written to %s.\n", file_name);
        }

        // Frees the memory allocated for the large number and the prime numbers list
        mpz_clear(maxLimit);
        for (unsigned long i = 0; i < size; i++)
            mpz_clear(primes[i]);
        free(primes);

        printf("\n\n");

        // Asks the user if they want to continue execution
        printf("Execute again? (y/n) ");
        scanf(" %c", &continueExecution);

        printf("\n\n");
    } while (continueExecution != 'n');

    return 0;
}
