#include <stdio.h>
#include <gmp.h>

/**
 * Authors          => Miguel Berenguer, Pedro Pita and Tomás Ferreira
 * Created At       => 04/01/2023
 * Last Edited At   => 04/01/2023
 * Version          => @v1.0 
 * 
 * Develop a program in C language using the GMP library, which allows you to obtain the
 * number of possible combinations of any total number of elements grouped into a
 * any number of elements per group.
*/

int main(void) {
    // Declare the mpz_t variables
    mpz_t result, n;
    unsigned int k;

    //Inicialize variables
    mpz_init_set_ui(result, 0);
    mpz_init(n);

    // read the total number and the total number of elements
    char str1[10000];
    printf("Enter the total number of grouped elements: ");
    scanf("%s", str1);
    mpz_set_str(n, str1, 10);

    printf("Enter the total number of elements per group: ");
    scanf("%u", &k);

    //Calculate the number of possible combinations of any number of elements grouped into any number of elements per group and store the result in result
    mpz_bin_ui(result, n, k);

    //Print the result
    gmp_printf("The number of combinations is: %Zd\n", result);

    return 0;
}
