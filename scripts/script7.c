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
 * Script that gets all prime numbers up to a limit given by the user.
 * It's using the Sieve of Eratosthenes algorithm.
 * This code was inspired by the folowing site:  https://www.geeksforgeeks.org/sieve-of-eratosthenes/
*/

int main(int argc, char *argv[]) {
    // Declares the variable to store the maximum limit
    mpz_t maxLimit;
    unsigned long maxLimitInput;

    // Loop until the user indicates that they want to exit
    char continueExecution;
    do {
        // Reads the maximum limit from the user input
        printf("Insert the limit: ");
        scanf("%lu", &maxLimitInput);

        // Initializes the large number with the maximum limit
        mpz_init_set_ui(maxLimit, maxLimitInput);

        // Creates a list of integers up to the maximum limit
        mpz_t *numbers;
        numbers = (mpz_t*)malloc((mpz_get_ui(maxLimit) + 1) * sizeof(mpz_t));
        for (unsigned long i = 0; i <= mpz_get_ui(maxLimit); i++)
            mpz_init_set_ui(numbers[i], i);

        // Applies the Sieve of Eratosthenes algorithm
        // Algorith explanation -> https://www.geeksforgeeks.org/sieve-of-eratosthenes/
        // Skip 0 and 1 as they are either prime nor composite
        for (unsigned long i = 2; i <= mpz_get_ui(maxLimit); i++) // Go throw all number until defined limit
            if (mpz_cmp_ui(numbers[i], 0) != 0) // 0 is a prime number
                for (unsigned long j = i * i; j <= mpz_get_ui(maxLimit); j += i) // Go theow all numbers that are multiple of i
                    mpz_set_ui(numbers[j], 0); // sets as prime number

        // Prints the prime numbers in the list
        printf("Prime numbers up to %d:\n", maxLimitInput);
        for (unsigned long i = 2; i <= mpz_get_ui(maxLimit); i++)
            if (mpz_cmp_ui(numbers[i], 0) != 0)  // just print if is not a prime number
                gmp_printf("%Zd\n", numbers[i]);

        // Frees the memory allocated for the list
        for (unsigned long i = 0; i <= mpz_get_ui(maxLimit); i++)
            mpz_clear(numbers[i]);
        free(numbers);

        printf("\n\n");

        // Asks the user if they want to continue execution
        printf("Execute again? (y/n) ");
        scanf(" %c", &continueExecution);

        printf("\n\n");
    } while (continueExecution != 'n');

    return 0;
}

