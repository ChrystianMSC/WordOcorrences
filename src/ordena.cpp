#include "ordena.h"
#include <iostream>

#define Troca(A, B) {string c = A; A = B; B = c; }


void Particao(int Esq, int Dir, int *i,int *j, string *A, int m)
{
    string x, w;
    *i = Esq; *j = Dir;
    x = A[(*i + *j)/2];
    do
    {
        while (x > A[*i])
        {
            (*i)++;
        }
        while (x < A[*j])
        {
            (*j)--;
        }
        if (*i <= *j)
        {
            w = A[*i]; A[*i] = A[*j]; A[*j] = w;
            (*i)++;
            (*j)--;
        }
    } while (*i <= *j);
}


void Ordena(int Esq, int Dir, string*A, int s, int m)
{
    int i, j;
    
    if (Esq + s > Dir)
    {
        selection(A, Dir, Esq);
        return;
    }
    else
    {
         Particao(Esq, Dir, &i, &j, A, m);
         if (Esq < j){
             Ordena(Esq, j, A, s, m);
         }
         if (i < Dir){
             Ordena(i, Dir, A, s, m);
         }
    }
}

void QuickSort(string *A, int n, int s, int m)
{
    Ordena(0, n - 1, A, s, m);
}


void selection(string* A, int Dir, int Esq) {
  int i, j, Min;
    for (i = Esq; i <= Dir; i++)
    {
        Min = i;
        for (j = i + 1 ; j <= Dir; j++)
        {
            if (A[j] < A[Min])
            Min = j;
        }
        Troca(A[i], A[Min]);
    }
}
