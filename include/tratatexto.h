#include <string>
#include <fstream>
#include <iostream>
#include <bits/stdc++.h>
#include "translate.h"
#include "ordena.h"
#include <sstream>

using namespace std;

#ifndef TRATATEXTO
#define TRATATEXTO

int contaPalavas(string aux2, char nome[]);
void verificaAbertura(ifstream &arquivo);
void leArquivo(string *text, string *ordem, string *aux, char nome[]);
string removeEspeciais(string text, string *ordem);
void tranformaMinusculo(string *text2, string *ordem2);
void setPalavras(string text, string ordem, string palavras[], int numPalavras);
void setOrdem(string *palavras, string ordem, int numPalavras, int s, int m);
void iniciaVetores(string semDupli[], int countPalavras[], int numPalavras);
void trataDuplicatas(int numPalavras, string palavras[], string semDupli[], int countPalavras[]);

#endif  // TRATATEXTO