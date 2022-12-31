#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

/**
 * Authors          => Miguel Berenguer, Pedro Pita and Tomás Ferreira
 * Created At       => 04/01/2023
 * Last Edited At   => 04/01/2023
 * Version          => @v1.0 
 * 
 * Script that asks the user two string numbers, and multiply them using gmp
*/
int main(void)
{
    // Declare variables for the two integers and the result
    mpz_t x, y, result;

    // Declare a string for input
    char input[100];

    // Initialize the variables
    mpz_init(x);
    mpz_init(y);
    mpz_init(result);

    printf("#### Multiplication of two inserted numbers as string ####\n");

    // Get the first integer from the user
    printf("Enter the first integer: ");
    scanf("%s", input);
    mpz_set_str(x, input, 10);

    // Get the second integer from the user
    printf("Enter the second integer: ");
    scanf("%s", input);
    mpz_set_str(y, input, 10);

    // Calculate the multiplication of the two integers and store the result in "result"
    mpz_mul(result, x, y);

    // Convert the result to a string and print it
    char *result_str = mpz_get_str(NULL, 10, result);
    printf("The result is: %s\n", result_str);

    // Free the result string
    free(result_str);

    return 0;
}
