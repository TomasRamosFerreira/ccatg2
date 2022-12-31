#include <stdio.h>
#include <gmp.h>
#include <stdlib.h>
#include <time.h>

/**
 * Authors          => Miguel Berenguer, Pedro Pita and Tomás Ferreira
 * Created At       => 04/01/2023
 * Last Edited At   => 04/01/2023
 * Version          => @v1.0 
 * 
 * Adapt the exercise 4 program to measure the execution time of the exponentiation function
 * used.
*/

int main(void)
{
    // Declare the variables
    mpz_t base, result;
    unsigned int exponent;
    clock_t start, end;
    double elapsed_ns, elapsed_s;

    //init variables
    mpz_init(base);
    mpz_init(result);

    //char to store the input
    char input[10000];

    //Read the base and exponent numbers
    printf("Insert the base number: ");
    scanf("%s", input);
    mpz_set_str(base, input, 10);
    
    printf("Insert the exponent number: ");
    scanf("%u", &exponent);
    
    //start the execution time calculation
    start = clock();

    //calculate the exponentiation
    mpz_pow_ui(result, base, exponent);

    //end the execution time calculation
    end = clock();

    //print the result
    char *result_str = mpz_get_str(NULL, 10, result);
    printf("Result: %s\n", result_str);

    //Convert the execution time from clock to nanoseconds
    elapsed_ns = (end - start) * 1000000000.0 / CLOCKS_PER_SEC;

    //Convert the execution time from nanoseconds to seconds
    elapsed_s = elapsed_ns / 1000000000.0;

    //print execution time
    printf("The execution time was %f nanoseconds == %f seconds \n", elapsed_ns, elapsed_s);

    return 0;
}