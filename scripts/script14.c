#include <stdio.h>
#include <gmp.h>


/**
 * Authors          => Miguel Berenguer, Pedro Pita and Tomás Ferreira
 * Created At       => 04/01/2023
 * Last Edited At   => 04/01/2023
 * Version          => @v1.0 
 * 
 * Develop a program in C language using the GMP library, which calculates a pair of keys
 * RSA of any dimension.
*/

int main(void) {
  // Declare as variáveis "mpz_t" para armazenar os valores de p, q, n, e, d e phi
  mpz_t p, q, n, e, d, phi, gcd;

  // Inicialize as variáveis "p" e "q" como números primos
  mpz_init(p);
  mpz_init(q);
  mpz_init(gcd);
  gmp_randstate_t rng;
  gmp_randinit_default(rng);

  // Solicitar ao usuário o número de bits desejado para as chaves RSA
  printf("Insira o número de bits desejado para as chaves RSA: ");
  int num_bits;
  scanf("%d", &num_bits);

  //random prime number
  do {
    mpz_urandomb(p, rng, num_bits);
  } while (mpz_probab_prime_p(p, 10) == 0);

  //random prime number
  do {
    mpz_urandomb(q, rng, num_bits);
  } while (mpz_probab_prime_p(q, 10) == 0);

  // Calcular n como o produto de p e q
  mpz_init(n);
  mpz_mul(n, p, q);

  // Calcular phi como o produto de (p-1) e (q-1)
  mpz_init(phi);
  mpz_sub_ui(p, p, 1);
  mpz_sub_ui(q, q, 1);
  mpz_mul(phi, p, q);

  // Escolher um valor para "e" tal que "e" e "phi" sejam primos entre si
  mpz_init(e);
  do {
    mpz_urandomb(e, rng, num_bits);
    mpz_gcd(gcd, e, phi);
  } while (mpz_cmp_ui(e, 1) <= 0 || mpz_cmp(e, phi) >= 0 || mpz_get_ui(gcd) != 1);

  // Calcular "d" como o inverso multiplicativo de "e" modulo "phi"
  mpz_init(d);
  mpz_invert(d, e, phi);

  // Exiba o valor de n, e e d
  gmp_printf("n = %Zd\n", n);
  gmp_printf("e = %Zd\n", e);
  gmp_printf("d = %Zd\n", d);
  printf("\n");

  //KU={e,n} e KR={d,n}
  printf("******KU={e,n} e KR={d,n}******");
  printf("\n\n");
  gmp_printf("KU => {\n%Zd, \n%Zd\n}", e, n);
  printf("\n");
  gmp_printf("KR => {\n%Zd, \n%Zd\n}", d, n);

  /**
    * Criptografar uma mensagem M, utilize a seguinte fórmula: C = M^e mod n. O resultado C é a mensagem criptografada.
    * Para descriptografar uma mensagem C, utilize a seguinte fórmula: M = C^d mod n. O resultado M é a mensagem original.
  */

  // Declare as variáveis "mpz_t" para armazenar os valores de M, e, n e C
  char input[10000], output[1000];
  mpz_t message, encrypted, decrypted;
  mpz_init(encrypted);
  mpz_init(decrypted);

  // Inicialize as variáveis com os valores desejados
  printf("\nInsert the message: ");
  scanf("%s", input);

  mpz_init_set_str(message, input, 0);

  // Calcule C = M^e mod n
  mpz_powm(encrypted, message, e, n);

  //gmp_printf("Converted to bits: %Zd \n", input);
  gmp_printf("Original message: %Zd \n", message);
  gmp_printf("Encrypted message: %Zd \n", encrypted);

  //desencriptar  mpz_powm(M, C, d, n)
  mpz_powm(decrypted, encrypted, d, n);

  gmp_printf("Decrypted message: %Zd", decrypted);

  // Limpe as variáveis e encerre o programa
  mpz_clear(p);
  mpz_clear(q);
  mpz_clear(n);
  mpz_clear(e);
  mpz_clear(d);
  mpz_clear(phi);
  return 0;
}