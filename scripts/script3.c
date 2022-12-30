#include <stdio.h>
#include <gmp.h>
#include <stdlib.h>

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
        printf("The number is probably prime.\n");
    } else if (result == 0) {
        printf("The number is composite.\n");
    } else {
        printf("The number is neither prime nor composite.\n");
    }

    // Clear the mpz_t variable
    mpz_clear(n);

    return 0;
}
