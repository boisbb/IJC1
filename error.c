//
//  error.c
//  Řešení IJC-DU1, příklad b), 10. 3. 2019
//  Autor: Boris Burkalo, FIT
// Přeloženo: gcc 7.3.0
//

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "error.h"

void warning_msg(const char *fmt, ...){

  va_list arguments;

  va_start(arguments, fmt);
  fprintf(stderr, "CHYBA: ");
  vfprintf(stderr, fmt, arguments);
  va_end(arguments);
}

void error_exit(const char *fmt, ...){
  va_list arguments;
  fprintf(stderr, "CHYBA: ");
  va_start(arguments, fmt);
  vfprintf(stderr, fmt, arguments);
  va_end(arguments);
  exit(1);
}
