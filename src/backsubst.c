#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int backsubst(Matrix *x, Matrix *mat, Matrix *b) {
	for (int i=0; i<x->r; i++) {
		x->data[i][0] = 1;
	}
		
	for(int i=mat->r-1; i>=0; i--){
		double tmp = b->data[i][0];
		for(int m=mat->c-1; m>=0; m--) {
			if (m != i) {
				tmp -= mat->data[i][m] * x->data[m][0];	
			}
		}
		if(mat->data[i][i]==0)
			return 1;
		tmp *= (1/mat->data[i][i]);
		x->data[i][0] = tmp;
	}

	if(mat->r != mat->c || mat->r != b->r)
		return 2;

	return 0;	
				
}


