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
 * The second param is the name of thew file to store the result.
 * It's using the Sieve of Eratosthenes algorithm.
 * This code was inspired by the folowing site:  https://www.geeksforgeeks.org/sieve-of-eratosthenes/
 */

int main(int argc, char *argv[])
{
    // Verifies the number of arguments
    if (argc < 2 || argc > 3)
    {
        // Give a user a info how to use the program
        fprintf(stderr, "Usage: %s <maximum limit> <file to store result>\n", argv[0]);
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

    if (argc == 3)
    {
        char *file_name = argv[2];

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

    return 0; // End program successefully
}
