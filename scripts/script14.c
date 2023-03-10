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
  // Declare the variables "mpz_t" 
  mpz_t p, q, n, e, d, phi, gcd;

  // Inicialize the variables
  mpz_init(p);
  mpz_init(q);
  mpz_init(gcd);
  gmp_randstate_t rng;
  gmp_randinit_default(rng);

  // Prompt user for desired number of bits for RSA keys
  printf("Enter the number of bits for the RSA keys: ");
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

  // Calculate n as the product of p and q
  mpz_init(n);
  mpz_mul(n, p, q);

  // Calculate phi as the product of (p-1) and (q-1)
  mpz_init(phi);
  mpz_sub_ui(p, p, 1);
  mpz_sub_ui(q, q, 1);
  mpz_mul(phi, p, q);

  // Value for "e" such that "e" and "phi" are mutually prime
  mpz_init(e);
  do {
    mpz_urandomb(e, rng, num_bits);
    mpz_gcd(gcd, e, phi);
  } while (mpz_cmp_ui(e, 1) <= 0 || mpz_cmp(e, phi) >= 0 || mpz_get_ui(gcd) != 1);

  // Calculate "d" as the multiplicative inverse of "e" modulo "phi"
  mpz_init(d);
  mpz_invert(d, e, phi);

  // Display the value of n, e, and d
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
}