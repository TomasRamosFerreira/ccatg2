#include <gmp.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Declares the variables needed to store large numbers
mpz_t result, base;

/**
 * Authors          => Miguel Berenguer, Pedro Pita and Tomás Ferreira
 * Created At       => 04/01/2023
 * Last Edited At   => 04/01/2023
 * Version          => @v1.0 
 * 
 * Script that compares the time of a pow operation,
 * between GMP and Iterable function.
*/

/**
 * Function that uses the GMP library 
 * to calculate the power of a large number raised to an integer power
 * */ 
void gmpSolution(int exponent) {
    mpz_pow_ui(result, base, exponent);
}

/**
 * Function that implements an iterative solution, 
 * to calculate the power of an integer raised to an integer power
 * */ 
int iterativeSolution(int base, int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

/**
 * Calculate the duration in seconds of the execution
*/
double executionTimeResult(clock_t startTime, clock_t endTime) {
    return (double)(endTime - startTime) / CLOCKS_PER_SEC;
} 

int main(int argc, char *argv[]) {
    // Initializes the declared variables
    int baseInt = 2;
    mpz_init(result);
    mpz_init(base);

    // Sets the value of the base to 2
    mpz_set_ui(base, baseInt);

    int exponent;
    char continueExecution;
    
    // Initiate start and end timers
    clock_t startTime, endTime;

    // Loop until the user indicates that they want to exit
    do {
        // Reads the exponent from the command line
        printf("Insert the exponet number: ");
        scanf("%d", &exponent);
        
        // Measures the execution time of the GMP solution
        startTime = clock();
        gmpSolution(exponent);
        endTime = clock();
        printf("Execution time of the GMP solution: %f seconds\n", executionTimeResult(startTime, endTime));
        gmp_printf("GMP solution result: %Zd\n\n", result);

        // Measures the execution time of the iterative solution
        startTime = clock();
        int iterativeSolutionResult = iterativeSolution(baseInt, exponent);
        endTime = clock();
        printf("Execution time of the iterative solution: %f seconds\n", executionTimeResult(startTime, endTime));
        printf("Iterative solution result: %d\n", iterativeSolutionResult);

        printf("\n\n");

        // Asks the user if they want to continue execution
        printf("Execute again? (y/n) ");
        scanf(" %c", &continueExecution);

        printf("\n\n");
    } while (continueExecution != 'n');

    return 0;
}
