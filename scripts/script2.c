#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

/**
 * Authors          => Miguel Berenguer, Pedro Pita and Tomás Ferreira
 * Created At       => 04/01/2023
 * Last Edited At   => 04/01/2023
 * Version          => @v1.0 
 * 
 * Develop a program in C language using the GMP library, which allows you to calculate the GCD
 * between two numbers of any size, and the numbers must be requested from the user, obtained
 * as strings and processed as mpz_t.
*/

int main(void)
{
    // Declare variables ​​mpz_t
    mpz_t n1, n2, gcd;

    // Initialize the variables ​​mpz_t
    mpz_init(n1);
    mpz_init(n2);
    mpz_init(gcd);

    // Read the entry numbers
    char str1[10000], str2[10000];
    printf("Digite o primeiro número: ");
    scanf("%s", str1);
    mpz_set_str(n1, str1, 10);

    printf("Digite o segundo número: ");
    scanf("%s", str2);
    mpz_set_str(n2, str2, 10);

    //Calculate the GCD between a and b, store the result in c
    mpz_gcd(gcd, n1, n2);

    char *result = mpz_get_str(NULL, 10, gcd);
    printf("O GCD entre os números é: %s\n", result);

    // Free the result string
    free(result);

    return 0;
}