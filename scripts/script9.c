#include <gmp.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * Author           => Tomás Ferreira
 * Created At       => 30/12/2022
 * Last Edited At   => 30/12/2022
 * Version          => @v1.0
 *
 * Script that gets all prime numbers up to a limit given by the user
 * And asks the user if he wants to store the result into a file
 * It's using the Sieve of Eratosthenes algorithm.
 * This code was inspired by the folowing site:  https://www.geeksforgeeks.org/sieve-of-eratosthenes/
 */

/**
 * Defines the function to calculate the prime numbers
 * @param maxLimit - Limit of the numer primes
 * @param size - Memory pointer that will store the size of the list of prime numbers
 * @return List of prime numbers
 */
mpz_t *calculatePrimes(mpz_t maxLimit, unsigned long *size)
{
    // Creates a list of integers up to the maximum limit
    mpz_t *numbers = (mpz_t *)malloc((mpz_get_ui(maxLimit) + 1) * sizeof(mpz_t));
    for (unsigned long i = 0; i <= mpz_get_ui(maxLimit); i++)
        mpz_init_set_ui(numbers[i], i);

    // Applies the Sieve of Eratosthenes algorithm
    // Algorith explanation -> https://www.geeksforgeeks.org/sieve-of-eratosthenes/
    // Skip 0 and 1 as they are either prime nor composite
    for (unsigned long i = 2; i <= mpz_get_ui(maxLimit); i++)                // Go throw all number until defined limit
        if (mpz_cmp_ui(numbers[i], 0) != 0)                                  // 0 is a prime number
            for (unsigned long j = i * i; j <= mpz_get_ui(maxLimit); j += i) // Go theow all numbers that are multiple of i
                mpz_set_ui(numbers[j], 0);                                   // sets as prime number

    // Counts the number of prime numbers in the list
    *size = 0;
    for (unsigned long i = 2; i <= mpz_get_ui(maxLimit); i++)
        if (mpz_cmp_ui(numbers[i], 0) != 0)
            (*size)++;

    // Allocates memory for the prime numbers list
    mpz_t *primes;
    primes = (mpz_t *)malloc(*size * sizeof(mpz_t));

    // Copies the prime numbers from the list to the prime numbers array
    unsigned long index = 0;
    for (unsigned long i = 2; i <= mpz_get_ui(maxLimit); i++)
    {
        if (mpz_cmp_ui(numbers[i], 0) != 0)
        {
            mpz_init_set(primes[index], numbers[i]);
            index++;
        }
    }

    // Frees the memory allocated for the list
    for (unsigned long i = 0; i <= mpz_get_ui(maxLimit); i++)
        mpz_clear(numbers[i]);
    free(numbers);

    return primes;
}

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

        printf("\n\n");

        // Asks the user if they want to save the prime numbers to a file
        char save_to_file;
        printf("Do you want to save the prime numbers to a file (Y/N)? ");
        scanf(" %c", &save_to_file);

        if (save_to_file == 'Y' || save_to_file == 'y') {
            // Asks the user for the file name
            printf("Enter the file name: ");
            char file_name[1024];
            scanf("%s", file_name);

            // Opens the file for writing
            FILE *file = fopen(file_name, "w+");
            if (file == NULL) {
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
