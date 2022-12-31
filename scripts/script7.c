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
    unsigned long maxLimitInput;

    // Loop until the user indicates that they want to exit
    char continueExecution;
    do
    {
        // Reads the maximum limit from the user input
        printf("Insert the limit: ");
        scanf("%lu", &maxLimitInput);

        // Initializes the large number with the maximum limit
        mpz_init_set_ui(maxLimit, maxLimitInput);

        // Calculates the prime numbers
        unsigned long size;
        mpz_t *primes = calculatePrimes(maxLimit, &size);

        // Prints the prime numbers
        printf("Prime numbers up to %Zd:\n", maxLimit);
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
