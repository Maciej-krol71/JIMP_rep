#ifndef _GAUSS_H
#define _GAUSS_H

#include "mat_io.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */

void switchrows(Matrix * mat, int j, int l);
double find_max(Matrix *mat, int j);
void redukcja(Matrix *mat, Matrix *b, double dziel, int i, int f);
int eliminate(Matrix *mat, Matrix *b);

#endif
