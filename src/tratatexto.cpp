#include "tratatexto.h"

int contaPalavas(string aux2, char nome[])
{
    ifstream arquivo;
    int numPalavras = 0;
    arquivo.open(nome);
    while (arquivo >> aux2)
    {
        ++numPalavras;
    }
    arquivo.close();
    numPalavras -= 28;
    return numPalavras;
}


void verificaAbertura(ifstream &arquivo)
{
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir arquivo" << endl;
        exit(1);
    }
}

void leArquivo(string *text, string *ordem, string *aux, char nome[])
{
    ifstream arquivo;
    arquivo.open(nome);
    
    verificaAbertura(arquivo);

    getline(arquivo, *aux);

    if (*aux == "#ORDEM")
    {
        while (getline(arquivo, *aux))
        {
            if (*aux == "#TEXTO")
            {
                while (getline(arquivo, *aux))
                {
                    *text += *aux;
                    *text += " ";
                }
                break;
            }
            *ordem += *aux;
        }
    }
    else if (*aux == "#TEXTO")
    {
        while (getline(arquivo, *aux))
        {
            if (*aux == "#ORDEM")
            {
                while (getline(arquivo, *aux))
                {
                    *ordem += *aux;
                }
                break;
            }
            *text += *aux;
            *text += " ";
        }
    }
    arquivo.close();
}

string removeEspeciais(string text, string *ordem)
{
    string ordemAux = *ordem;
    text.erase(remove(text.begin(), text.end(), '?'), text.end());
    text.erase(remove(text.begin(), text.end(), ':'), text.end());
    text.erase(remove(text.begin(), text.end(), ';'), text.end());
    text.erase(remove(text.begin(), text.end(), '_'), text.end());
    text.erase(remove(text.begin(), text.end(), ','), text.end());
    text.erase(remove(text.begin(), text.end(), '.'), text.end());
    text.erase(remove(text.begin(), text.end(), '!'), text.end());
    ordemAux.erase(remove(ordemAux.begin(), ordemAux.end(), ' '), ordemAux.end());
    *ordem = ordemAux;
    
    return text;
}

void tranformaMinusculo(string *text2, string *ordem2)
{
    string text = *text2;
    string ordem = *ordem2;
    transform(text.begin(), text.end(), text.begin(), ::tolower);
    transform(ordem.begin(), ordem.end(), ordem.begin(), ::tolower);
    *text2 = text;
    *ordem2 = ordem;
}


void setPalavras(string text, string ordem, string palavras[], int numPalavras)
{
    stringstream iss(text);
    for (int i = 0; i < numPalavras; ++i)
    {
        iss >> palavras[i];

        for (size_t j = 0; j < palavras[i].length(); ++j)
        { 
            palavras[i][j] = translateChar(palavras[i][j], ordem); 
        }
    }
}

void setOrdem(string *palavras, string ordem, int numPalavras, int s, int m)
{
    QuickSort(palavras, numPalavras, s, m);

    for (int i = 0; i < numPalavras; ++i)
    {
        for (size_t j = 0; j < palavras[i].length(); ++j)
        { 
            palavras[i][j] = undoTranslate(palavras[i][j], ordem); 
        }
    }
}


void iniciaVetores(string semDupli[], int countPalavras[], int numPalavras)
{
    for (int i = 0; i < numPalavras; i++)
    {
        semDupli[i] = "null";
    }
    for (int i = 0; i < numPalavras; i++)
    {
        countPalavras[i] = 0;
    }
}

void trataDuplicatas(int numPalavras, string palavras[], string semDupli[], int countPalavras[])
{
    
    int tem = 0;
    for(int i = 0; i < numPalavras; i++)
    {
        tem = 0;
        string word = palavras[i];
        for (int j = 0; j < numPalavras; j++)
        {
            if (word == semDupli[j])
            {
                tem = 1;
                break;
            }
        }
        if (tem == 0)
        {
            semDupli[i] = word;
        }
    }


    for (int i = 0; i < numPalavras; i++)
    {
        if (semDupli[i] == "null")
        {
            continue;
        }
        for (int j = 0; j < numPalavras; j++)
        {
            if (semDupli[i] == palavras[j])
            {
                countPalavras[i]++;
            }
        }
    }

}