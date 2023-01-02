#include <stdio.h>
#include <gmp.h>
#include <stdlib.h>

/**
 * Authors          => Miguel Berenguer, Pedro Pita and Tomás Ferreira
 * Created At       => 04/01/2023
 * Last Edited At   => 04/01/2023
 * Version          => @v1.0 
 * 
 * Develop a program in C language using the GMP library, which allows you to calculate the
 * exponentiation of two integers of any dimension, and the numbers must be asked to the
 * user, obtained as strings and processed as mpz_t. Consider the possibility of defining a
 * enough modular arithmetic for your operations. The program should run in a loop, order
 * the numbers relative to the base and the power and calculating the respective exponentiation in each case, until
 * to select the exit option.
*/

int main(void)
{
    // Declare the variables
    mpz_t base, result;
    unsigned int exponent;

    //init variables
    mpz_init(base);
    mpz_init(result);

    //char to store the input
    char input[10000];

    //Execute the main cicle
    while (1) {
        //Read the base and exponent numbers
        printf("Insert the base number: ");
        scanf("%s", input);
        mpz_set_str(base, input, 10);
        
        printf("Insert the exponent number: ");
        scanf("%u", &exponent);
        
        //calculate the exponentiation
        mpz_pow_ui(result, base, exponent);

        //print the result
        char *result_str = mpz_get_str(NULL, 10, result);
        printf("Result: %s\n", result_str);

        // Ask the user if they want to continue or exit the program
        printf("Do yout want to continue (S/N)? ");
        scanf("%s", input);

        if (input[0] == 'N' || input[0] == 'n') {
            printf("Bye");
            break;
        }
    }
}