//
//  ppm.c
//  Řešení IJC-DU1, příklad b), 10. 3. 2019
//  Autor: Boris Burkalo, FIT
// Přeloženo: gcc 7.3.0
//

#include <stdio.h>
#include <stdlib.h>
#include "ppm.h"

struct ppm *ppm_read(const char *filename) {

  FILE *PPM_file = fopen(filename, "r");
  char format[3];
  int width;
  int height;
  int depth;
  int scan_check = 0;
  int frea = 0;

  if(PPM_file == NULL){
    warning_msg("nepodařilo se úspěšně přečíst soubor.\n");
    fclose(PPM_file);
    return NULL;
  }

  scan_check = fscanf(PPM_file, "%s %d %d %d ", format, &width, &height, &depth);
  if(scan_check != 4){
    warning_msg("ze souboru .ppm, se nepodařilo správně načíst data.\n");
    fclose(PPM_file);
    return NULL;
  }

  struct ppm *PPM_specifiers = malloc(sizeof(struct ppm) + 3*width*height);
  if(PPM_specifiers == NULL){
    warning_msg("nedošlo k alokaci paměti.\n");
    ppm_free(PPM_specifiers);
    fclose(PPM_file);
    return NULL;
  }

  frea = fread(PPM_specifiers->data, sizeof(char), 3*width*height, PPM_file);
  if(frea != 3*height*width){
    warning_msg("špatně zadány specifikace obrázku.");
    ppm_free(PPM_specifiers);
    fclose(PPM_file);
    return NULL;
  }

  PPM_specifiers->xsize = width;
  PPM_specifiers->ysize = height;
  fclose(PPM_file);
  return PPM_specifiers;
}

void ppm_free(struct ppm *p){
  free(p);
  return;
}
