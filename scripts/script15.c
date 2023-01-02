#include <stdio.h>
#include <gmp.h>
#include <time.h>


/**
 * Authors          => Miguel Berenguer, Pedro Pita and Tomás Ferreira
 * Created At       => 04/01/2023
 * Last Edited At   => 04/01/2023
 * Version          => @v1.0 
 * 
 * Develop a program in C language using the GMP library, which calculates a pair of keys
 * RSA of any dimension.
*/

/*
clock_t start, end;
double elapsed_ns, elapsed_s;
start = clock();
end = clock();
//Convert the execution time from clock to nanoseconds
elapsed_ns = (end - start) * 1000000000.0 / CLOCKS_PER_SEC;
//Convert the execution time from nanoseconds to seconds
elapsed_s = elapsed_ns / 1000000000.0;
//print execution time
printf("The execution time was %f nanoseconds == %f seconds \n", elapsed_ns, elapsed_s);
*/

void calculateTime(clock_t end, clock_t start, char* message){
  double elapsed_ns, elapsed_s;
  //Convert the execution time from clock to nanoseconds
  elapsed_ns = (end - start) * 1000000000.0 / CLOCKS_PER_SEC;
  //Convert the execution time from nanoseconds to seconds
  elapsed_s = elapsed_ns / 1000000000.0;
  //print execution time
  printf("%s %f nanoseconds == %f seconds \n", message, elapsed_ns, elapsed_s);
}

int main(void) {
  // Declare the variables "mpz_t" 
  mpz_t p, q, n, e, d, phi, gcd;

  // Inicialize the variables
  mpz_init(p);
  mpz_init(q);
  mpz_init(gcd);
  gmp_randstate_t rng;
  gmp_randinit_default(rng);

  //time vars
  clock_t start, end;
  double elapsed_ns, elapsed_s;

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
  start = clock();
  mpz_init(n);
  mpz_mul(n, p, q);
  end = clock();
  calculateTime(end, start, "\nTime calculating n as the product of p and q:");

  // Calculate phi as the product of (p-1) and (q-1)
  start = clock();
  mpz_init(phi);
  mpz_sub_ui(p, p, 1);
  mpz_sub_ui(q, q, 1);
  mpz_mul(phi, p, q);
  end = clock();
  calculateTime(end, start, "Time calculating phi as the product of (p-1) and (q-1):");

  // Value for "e" such that "e" and "phi" are mutually prime
  start = clock();
  mpz_init(e);
  do {
    mpz_urandomb(e, rng, num_bits);
    mpz_gcd(gcd, e, phi);
  } while (mpz_cmp_ui(e, 1) <= 0 || mpz_cmp(e, phi) >= 0 || mpz_get_ui(gcd) != 1);
  end = clock();
  calculateTime(end, start, "Time getting the value for 'e' such that 'e' and 'phi' are mutually prime:");

  // Calculate "d" as the multiplicative inverse of "e" modulo "phi"
  start = clock();
  mpz_init(d);
  mpz_invert(d, e, phi);
  end = clock();
  calculateTime(end, start, "Time calculating 'd' as the multiplicative inverse of 'e' modulo 'phi': \n");

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

  /**
    * Eencrypt a message M: C = M^e mod n. Result C is the encrypted message.
    * Decrypt a C message:  M = C^d mod n. The result M is the original message.
  */
}