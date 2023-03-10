#include <stdio.h>
#include <gmp.h>

/**
 * Authors          => Miguel Berenguer, Pedro Pita and Tomás Ferreira
 * Created At       => 04/01/2023
 * Last Edited At   => 04/01/2023
 * Version          => @v1.0 
 * 
 * Change the program for exercise 12 so that the text file inspired in each line the factorization
 * of two prime numbers and the prime numbers that gave rise to it. Each line must therefore
 * contain three numbers, the first being the result of the factorization and the second and third the numbers
 * Primes involved in the respective factorization.
*/

int main(void) {
  // Declare the variables
  mpz_t limit;
  char filename[256];
  char input[256];
  FILE *file;

  // Inicialize the variables
  mpz_init(limit);

  //Execute the main cicle
  while (1) {
    //Read the maximum limit and the text file name
    printf("Insert the maximum limit: ");
    scanf("%s", input);
    mpz_set_str(limit, input, 10);
    printf("Insert the text file name: ");
    scanf("%s", filename);

    // Open text file for writing, if the file dont exist, will be created 
    file = fopen(filename, "w");

    //Check if the file was successfully opened
    if (file == NULL) {
      printf("Error opening the file.\n");
      continue;
    }

    // Cycle through integers from 2 (because is less than 1) to the maximum limit
    mpz_t i,j,fac1,fac2,result;

    mpz_init(i);
    mpz_init(j);
    mpz_init(fac1);
    mpz_init(fac2);
    mpz_init(result);
    unsigned int aux;

    mpz_set_ui(i, 2);
    mpz_set_ui(j, 0);

    while (mpz_cmp(i, limit) < 0) {
      // Check if the number is prime
      if (mpz_probab_prime_p(i, 10) > 0) {
        if(mpz_sgn(j) == 0){
          mpz_set(j, i);
        }else{
          // Write prime number to text file
          aux = mpz_get_ui(j); //first number
          mpz_fac_ui(fac1, aux);

          aux = mpz_get_ui(i); //second number
          mpz_fac_ui(fac2, aux);

          //somar os dois valores
          mpz_add(result, fac1, fac2);

          fprintf(file, "Result=");
          mpz_out_str(file, 10, result);
          fprintf(file, " J=");
          mpz_out_str(file, 10, j);
          fprintf(file, " I=");
          mpz_out_str(file, 10, i);
          fprintf(file, "\n");
          mpz_set_ui(j, 0);
        }
      }

      // Increment the counter
      mpz_add_ui(i, i, 1);
    }
    mpz_clear(i);

    // Close the text file
    fclose(file);

    // Ask the user if they want to continue or exit the program
    printf("Do yout want to continue (S/N)? ");
    scanf("%s", input);
    if (input[0] == 'N' || input[0] == 'n') {
      break;
    }
  }
  
  return 0;
}
