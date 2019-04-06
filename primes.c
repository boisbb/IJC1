//
//  primes.c
//  Řešení IJC-DU1, příklad a), 10. 3. 2019
//  Autor: Boris Burkalo, FIT
// Přeloženo: gcc 7.3.0
//

#include <stdio.h>
#include "error.c"
#include "math.h"
#include "bit_array.h"
#include "eratosthenes.c"

int main(int argc, char const *argv[]) {
  bit_array_create(array, 123000000);
  int last_ten[10];
  Eratosthenes(array);
  int i = 123000000 - 1;
  int n = 1;
  while(n <= 11){
    if(bit_array_getbit(array, i) == 0 && n <= 10){
      last_ten[n - 1] = i;
      n++;
    }
    else if(n > 10){
      for(int i = 9; i >= 0; i--){
        printf("%d\n", last_ten[i]);
      }
      return 0;
    }
    i--;
  }
}
