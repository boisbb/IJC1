//
//  error.h
//  Řešení IJC-DU1, příklad b), 10. 3. 2019
//  Autor: Boris Burkalo, FIT
// Přeloženo: gcc 7.3.0
//

void warning_msg(const char *fmt, ...);
/*
fmt = format
use of vfprinf needed
fctions have same parametres as fprintf
they print errors on stderr based on what went wrong
*/


void error_exit(const char *fmt, ...);
