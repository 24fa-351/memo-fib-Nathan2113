#include <stdio.h>
#include <string.h>
#include <stdlib.h>

__uint64_t fib_i_core(int number);
__uint64_t fib_r_core(int number);
__uint64_t fib_r(int number);
__uint64_t fib_i(int number);

long int fib_table[100];

// For this program, argv[0] is fib, argv[1] is the integer we are calculating the fibonacci for, argv[2] is the method, and argv[3] is the file
   // The methods include: 'r' for recursion, and 'i' for iterative
   
int main(int argc, char* argv[]) { // argc is the argument count and argv is a vector of arguments
   if(argc < 3) {
      printf("[-] Must pass an integer and either 'i' or 'r' as command line arguements\n");
      printf("[-] EXAMPLE: ./fib 5 r\n");
   } // END if(argc < 3)
   else {
      int fib_counter = 0; // This integer will read from the input file, and add that value to the integer arguement passed by the user

      // TESTING - file input read
      // printf("Number in the file: %u\n", file_number);

      fib_counter = atoi(argv[1]) - 1;
      
      // strcmp returns 0 if the strings are equal
      if(!strcmp(argv[2], "i")) { // Iterative implementation of fibonacci
         __uint64_t fibonacci_answer = fib_i_core(fib_counter);

         printf("%lu", fibonacci_answer);
      } // END if(argv[2] == 'i')
      else if(!strcmp(argv[2], "r")) { // Recursive implementation of fibonacci
         __uint64_t fibonacci_answer = fib_r_core(fib_counter);

         // printf("The answer is %lu\n", fibonacci_answer);
         printf("%lu", fibonacci_answer);
      } // END else else if(argv[2] == 'r')
      else {
         printf("[-] Invalid argument...Must pass in either 'i' or 'r'\n");
         printf("[-] EXAMPLE: ./fib 5 r\n");
         printf("Testing argv[2]: %s\n", argv[2]);
      }
   } // END else

   return 0;
}

// Recursive implementation of fibonacci
__uint64_t fib_r_core(int number) {
   // This is the original implementation of fibonacci using recursion
   // if(number == 0) {
   //    return 0;
   // } // END if(number == 0)
   // else if(number == 1) {
   //    return 1;
   // } // END else if(number == 1)

   // return fibRecursion(number - 1) + fibRecursion(number - 2);

   // This is the fibonacci implementation using memoization
   return fib_r(number);
}

__uint64_t fib_i_core(int number) {
   // This is the original implementation of fibonacci using iteration

   // __uint64_t current_number = 1; // __uint64_t can hold up to 18446744073709551615
   // __uint64_t prev_number = 0;
   // __uint64_t prev_prev_number = 0;

   // if(number == 0) {
   //    current_number = 0;
   // } // END if(fib_counter == 0)
   // else {
   //    for(int i = 1; i < number; i++) {
   //       prev_prev_number = prev_number;
   //       prev_number = current_number;
   //       current_number = prev_prev_number + prev_number;
   //    }// END for(int i = 1; i < argv[1]; i++)
   // } // END else
         
   // printf("%lu", current_number);

   return fib_i(number);
}

__uint64_t fib_r(int number) {
   if(fib_table[number] == 0) {
      if(number <= 1) {
         fib_table[number] = number;
      } // END if(number <= 1)
      else {
         fib_table[number] = fib_r(number - 1) + fib_r(number - 2);
      } // END else
   } // END if(fib_table[number] == NULL)

   return fib_table[number];
}

__uint64_t fib_i(int number) {
   __uint64_t iterative_table[300];
   int fib_count = 0;

   for(int i = 0; i <= number; i++) {
      if(i == 0 || i == 1) {
         iterative_table[i] = i;
      } // END if(i == 0 || i == 1)
      else {
         iterative_table[i] = iterative_table[i - 2] + iterative_table[i - 1];
      }

      fib_count++;
   } // END for(int i = 0; i < number; i++)
   fib_count--;

   return iterative_table[fib_count];
}