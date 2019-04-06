//
//  steg-decode.c
//  Řešení IJC-DU1, příklad b), 10. 3. 2019
//  Autor: Boris Burkalo, FIT
// Přeloženo: gcc 7.3.0
//

#include <stdio.h>
#include "error.c"
#include "math.h"
#include "bit_array.h"
#include "eratosthenes.c"
#include "ppm.c"

int main(int argc, char const *argv[]) {
  if(argc != 2){
    error_exit("nesprávný počet argumentů\n");
  }
  struct ppm *ppm_file = ppm_read(argv[1]);
  bit_array_alloc(array, (3*ppm_file->xsize*ppm_file->ysize));
  if(array == NULL){
    error_exit("nepodařilo se alokovat požadovanou paměť.\n");
  }
  Eratosthenes(array);
  int byte = 0;
  bit_array_create(character, 8);
  int character_1 = 1;
  for(int i = 19; i <= 3*ppm_file->xsize*ppm_file->ysize; i++){
      if(bit_array_getbit(array, (i)) == 0 && byte < 8){
        if(((ppm_file->data[i]) & 1) == 1){
          bit_array_setbit(character, byte, 1);
        }
        byte++;
      }
      character_1 = character[1];
      if(byte > 7){
        printf("%c", character_1);
        byte = 0;
        character[1] = 0;
      }
      else if(character_1 == 0 && byte == 7){
        printf("\n");
        break;
      }
    }
    bit_array_free(array);
  ppm_free(ppm_file);
  return 0;
}
