#include <stdio.h>
#include <gmp.h>
#include <stdlib.h>

/**
 * Authors          => Miguel Berenguer, Pedro Pita and Tomás Ferreira
 * Created At       => 04/01/2023
 * Last Edited At   => 04/01/2023
 * Version          => @v1.0 
 * 
 * Develop a program in C language using the GMP library, which allows you to determine whether
 * a number is Prime, the number must be requested from the user, obtained as a string and processed like mpz_t.
*/

int main(void) {
    // Declare a variable of type mpz_t to store the number
    mpz_t n;

    // Initialize the mpz_t variable
    mpz_init(n);

    // Read the number from the user
    printf("Enter a number: ");
    gmp_scanf("%Zd", n);

    // Check if the number is prime
    int result = mpz_probab_prime_p(n, 25);

    // Print the result
    if (result > 0) {
        printf("Is prime.\n");
    } else if (result == 0) {
        printf("Is composite.\n");
    } else {
        printf("Is not prime and composite.\n");
    }

    // Clear the mpz_t variable
    mpz_clear(n);

    return 0;
}
