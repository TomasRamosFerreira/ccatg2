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
 * Script that gets all prime numbers up to a limit given by the user, from the param.
 * It's using the Sieve of Eratosthenes algorithm.
 * This code was inspired by the folowing site:  https://www.geeksforgeeks.org/sieve-of-eratosthenes/
 */

int main(int argc, char *argv[])
{
    // Verifies the number of arguments
    if (argc != 2)
    {
        // Give a user a info how to use the program
        fprintf(stderr, "Usage: %s <maximum limit>\n", argv[0]);
        return 1; // end program as error
    }

    // Declares the variable to store the maximum limit
    mpz_t maxLimit;
    unsigned long size;

    // Initialize variable
    mpz_init(maxLimit);

    // Parses the maximum limit from the string
    mpz_set_str(maxLimit, argv[1], 10);

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

    return 0; // End program successefully
}
