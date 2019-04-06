//
//  eratosthenes.c
//  Řešení IJC-DU1, příklad a), 10. 3. 2019
//  Autor: Boris Burkalo, FIT
// Přeloženo: gcc 7.3.0
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void Eratosthenes(bit_array_t array){
  unsigned long number = bit_array_size(array);
  bit_array_setbit(array, 1, 1);
  bit_array_setbit(array, 0, 1);
  for(unsigned long i = 1; i < sqrt(number); i++){
    if(bit_array_getbit(array, i) == 1){
      continue;
    }
    else if(bit_array_getbit(array, i) == 0){
      for(unsigned long n = 2; (n * i) < number; n++){
        bit_array_setbit(array, n * i, 1);
      }
    }
  }
}
