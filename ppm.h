//
//  ppm.h
//  Řešení IJC-DU1, příklad b), 10. 3. 2019
//  Autor: Boris Burkalo, FIT
// Přeloženo: gcc 7.3.0
//

struct ppm {
  unsigned xsize;
  unsigned ysize;
  char data[];
};

struct ppm *ppm_read(const char *filename);

void ppm_free(struct ppm *p);
