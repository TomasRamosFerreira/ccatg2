#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

int main(void)
{
    // Declara as variáveis ​​mpz_t
    mpz_t a, b, c;

    // Inicializa as variáveis ​​mpz_t
    mpz_init(a);
    mpz_init(b);
    mpz_init(c);

    // Lê os números de entrada como strings
    char str1[10000], str2[10000];
    printf("Digite o primeiro número: ");
    scanf("%s", str1);
    mpz_set_str(a, str1, 10);

    printf("Digite o segundo número: ");
    scanf("%s", str2);
    mpz_set_str(b, str2, 10);

    mpz_gcd(c, a, b);

    char *result = mpz_get_str(NULL, 10, c);
    printf("O GCD entre os números é: %s\n", result);
}