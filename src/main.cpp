#include "tratatexto.h"

using namespace std;

#include <getopt.h>
#include <cstring>

char file_name[100];
char output_file_name[100];
int m, s;

void parse_args(int argc,char ** argv) {

    extern char * optarg;
    int c;

    file_name[0] = 0;
    output_file_name[0] = 0;
    m = -1;
    s = -1;

    while ((c = getopt(argc, argv, "i:I:m:M:s:S:o:O:h")) != EOF) {
        switch(c) {
            case 'i':
            case 'I':
                strcpy(file_name,optarg);
                break;

            case 'm':
            case 'M':
                m = atoi(optarg);
                break;

            case 's':
            case 'S':
                s = atoi(optarg);
                break;

            case 'o':
            case 'O':
                strcpy(output_file_name,optarg);
                break;
        }
    }
}

int main(int argc, char ** argv)
{
    parse_args(argc,argv);

    string aux, aux2, text, ordem;

    int numPalavras;
    numPalavras = contaPalavas(aux2, file_name);

    string palavras[numPalavras];
    string semDupli[numPalavras];
    int countPalavras[numPalavras];

    iniciaVetores(semDupli, countPalavras, numPalavras);
    leArquivo(&text, &ordem, &aux, file_name);
    tranformaMinusculo(&text, &ordem);
    text = removeEspeciais(text, &ordem);
    setPalavras(text, ordem, palavras, numPalavras);
    setOrdem(palavras, ordem, numPalavras, s, m);
    trataDuplicatas(numPalavras, palavras, semDupli, countPalavras);



    for (int i = 0; i < numPalavras; i++)
    {
        if (semDupli[i] == "null")
        {
            continue;
        }
        cout << semDupli[i] << " ";
        cout << countPalavras[i] << endl;
    }


    return 0;
}