#include <stdio.h>
#include <gmp.h>

/**
 * Authors          => Miguel Berenguer, Pedro Pita and Tomás Ferreira
 * Created At       => 04/01/2023
 * Last Edited At   => 04/01/2023
 * Version          => @v1.0 
 * 
 * Develop a program in C language using the GMP library, which allows you to obtain a
 * listing in a text file, the factorization of all Prime numbers less than one
 * certain maximum limit, and the maximum limit must be requested from the user, obtained as a string and
 * rendered as mpz_t. The program should run in a cycle, asking for the maximum limit and the name of the
 * text file, calculating the Prime numbers smaller than that limit, calculating the combinations
 * possible combinations of all Prime numbers two by two, calculating the factorization of all combinations
 * and writing in the text file a result of a factorization per line, until selected
 * the exit option.
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

          mpz_out_str(file, 10, result);
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
      printf("Bye");
      break;
    }
  }
  
  return 0;
}
