#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */

void switchrows(Matrix *mat, int j, int l) {
	double * tmp = mat->data[j];
	mat->data[j] = mat->data[l];
	mat->data[l] = tmp;
}

void find_max(Matrix *mat, Matrix *b, int j) {
	int i;
	int l = j;
        double max = mat->data[j][j];
        for (i=j; i<mat->r; i++) {
		if(mat->data[i][j] > max) {
			max = mat->data[i][j];
			l = i;
		}
	}
	switchrows(mat, j, l);
	switchrows(b, j, l);
}

void redukcja(Matrix *mat, Matrix *b, double dziel, int i, int f) {
	int h;
	for (h=0; h<mat->c; h++) {
		mat->data[f][h] = mat->data[f][h] - mat->data[i][h] * dziel;
	}
	b->data[f][0] = b->data[f][0] - b->data[i][0] * dziel;
}

int eliminate(Matrix *mat, Matrix *b){
    	int i;
	for (i=0; i<mat->r; i++) {
		find_max(mat, b, i);
		int k;
		for(k=1; k<mat->r-i; k++) {
			redukcja(mat, b, mat->data[i+k][i] / mat->data[i][i], i, i+k);
		}
	}

		return 0;
}

