//
//  bit_array.h
//  Řešení IJC-DU1, příklad a), 10. 3. 2019
//  Autor: Boris Burkalo, FIT
// Přeloženo: gcc 7.3.0
//


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

unsigned long x = 1;
unsigned long y = 0;
unsigned long size = 0;
int dynamic = 0;


typedef unsigned long *bit_array_t;

#define bit_array_create(jmeno_pole, velikost) \
    unsigned long jmeno_pole[(velikost % ((sizeof(unsigned long) * 8)) == 0) ? ((velikost / (sizeof(unsigned long) * 8)) + 1) : ((velikost / (sizeof(unsigned long) * 8)) + 2)] = {velikost, 0}; \
    static_assert(((velikost > 0) && (velikost < ULONG_MAX)), "Pozadovana velikost je 0 nebo je mimo meze unsigned long.")
    /*
    creates and initializes array jmeno_pole
    .
    .
    initialization of "velikost" + 1 --> index 0 is used for size of the array
    */
#define bit_array_alloc(jmeno_pole, velikost) \
    assert((velikost) > 0); \
    unsigned long *jmeno_pole = malloc(sizeof(unsigned long) * (velikost / sizeof(unsigned long) / 8) + 1); \
    do{ \
      jmeno_pole[0] = velikost; \
      dynamic = 1; \
      for(int i = 1; i < (velikost / 8 / 8); i++){ \
        jmeno_pole[i] = 0; \
      } \
    } while(0)

        /*
        takes care of dynamic allocation of array
        .
        .
        */
#define bit_array_free(jmeno_pole) (free(jmeno_pole))
    /*
    frees allocated memory
    .
    .

    */
#ifdef USE_INLINE
  extern inline unsigned long bit_array_size(bit_array_t jmeno_pole){
    return jmeno_pole[0];
  }
#else
  #define bit_array_size(jmeno_pole) (jmeno_pole[0])
    /*
    returns array size in bits
    .
    .
    */
#endif

#ifdef USE_INLINE
  extern inline void bit_array_setbit(bit_array_t jmeno_pole, unsigned long index, unsigned long vyraz){
    unsigned long help = vyraz;
    if(index >= bit_array_size(jmeno_pole)){
      error_exit("index %ld je mimo rozsah pole s velikostí: %ld\n", index, bit_array_size(jmeno_pole));
    }
    else if(vyraz > 1 || vyraz < 0){
      error_exit("výraz není 1 nebo 0 | hodnota výrazu je: %d\n", vyraz);
    }
    else{
      help = help << (index % (sizeof(*jmeno_pole) * 8));
      jmeno_pole[(index + (sizeof(*jmeno_pole) * 8)) / (sizeof(*jmeno_pole) * 8)] |= help;
    }
  }
#else
  #define bit_array_setbit(jmeno_pole, index, vyraz) y = vyraz; ((index) >= bit_array_size(jmeno_pole) || vyraz > 1 || vyraz < 0) ? error_exit("index %ld je mimo rozsah pole s velikostí: %ld\n", index, bit_array_size(jmeno_pole)), 0 : (jmeno_pole[(index + (sizeof(*jmeno_pole) * 8)) / (sizeof(*jmeno_pole) * 8)] |= (y << ((index) % (sizeof(*jmeno_pole) * 8))));
      /*
      sets bit of an array on the position of index
      .
      .
      */
#endif

#ifdef USE_INLINE
  extern inline unsigned long bit_array_getbit(bit_array_t jmeno_pole, unsigned long index){
    unsigned long help = 1;
    if(index >= bit_array_size(jmeno_pole)){
      error_exit("index %ld je mimo rozsah pole s velikostí: %ld\n", index, bit_array_size(jmeno_pole));
      return 0;
    }
    else{
      help = help << (index % (sizeof(*jmeno_pole) * 8));
      return ((jmeno_pole[(index + (sizeof(*jmeno_pole) * 8)) / (sizeof(*jmeno_pole) * 8)] & help) >> ((index) % (sizeof(*jmeno_pole) * 8)));
    }
  }
#else
  #define bit_array_getbit(jmeno_pole, index)((index) >= bit_array_size(jmeno_pole)) ? error_exit("index %ld je mimo rozsah pole s velikostí: %ld\n", index, bit_array_size(jmeno_pole)), 0 : ((jmeno_pole[(index + (sizeof(*jmeno_pole) * 8)) / (sizeof(*jmeno_pole) * 8)] & (x << ((index ) % (sizeof(*jmeno_pole) * 8)))) >> ((index) % (sizeof(*jmeno_pole) * 8)))
      /*
      returns value of bit on index
      .
      .
      */
#endif
