#include <stdio.h>
#include <gmp.h>
#include <stdlib.h>

int main(void)
{
    mpz_t base, resultado;
    unsigned int expoente;

    mpz_init(base);
    mpz_init(resultado);

    char input[10000];

    printf("Insira a base: ");
    scanf("%s", input);
    
    printf("Insira o expoente: ");
    scanf("%u", &expoente);
    
    mpz_set_str(base, input, 10); // 10 indica que a base é a decimal

    mpz_pow_ui(resultado, base, expoente); //calcula a exponenciação

    char *resultado_str = mpz_get_str(NULL, 10, resultado);
    printf("Resultado: %s\n", resultado_str);
}