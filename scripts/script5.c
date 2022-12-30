#include <stdio.h>
#include <gmp.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    mpz_t base, resultado;
    unsigned int expoente;
    clock_t start, end;
    double elapsed_ns, elapsed_s;

    mpz_init(base);
    mpz_init(resultado);

    char input[10000];

    printf("Insira a base: ");
    scanf("%s", input);
    
    printf("Insira o expoente: ");
    scanf("%u", &expoente);
    
    mpz_set_str(base, input, 10); // 10 indica que a base é a decimal

    start = clock();
    mpz_pow_ui(resultado, base, expoente); //calcula a exponenciação
    end = clock();

    //Imprimir o resultado
    char *resultado_str = mpz_get_str(NULL, 10, resultado);
    printf("Resultado: %s\n", resultado_str);

    //Medir tempo de execução
    // Converter o tempo de execução em segundos
    elapsed_ns = (end - start) * 1000000000.0 / CLOCKS_PER_SEC;
    elapsed_s = elapsed_ns / 1000000000.0;
    printf("O tempo de execução foi de %f nanosegundos == %f segundos \n", elapsed_ns, elapsed_s);
    
    return 0;
}