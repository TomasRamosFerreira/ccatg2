#include <gmp.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "calculatePrimes.c"

/**
 * Author           => Tomás Ferreira
 * Created At       => 30/12/2022
 * Last Edited At   => 31/12/2022
 * Version          => @v3.0
 *
 * Script that gets all prime numbers up to a limit given by the user.
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
