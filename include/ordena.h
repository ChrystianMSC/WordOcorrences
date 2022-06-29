#include <string>

using namespace std;

#ifndef ORDENA
#define ORDENA

void Particao(int Esq, int Dir, int *i,int *j, string *A, int m);

void Ordena(int Esq, int Dir, string*A, int s, int m);

void QuickSort(string *A, int n, int s, int m);

void selection(string* A, int Dir, int Esq);

#endif // ORDENA