#ifndef LOGICA_H
#define LOGICA_H
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <map>

using namespace std;

class Logica
{
public:
    vector<string> GeraLinhaParametros(char* linhas_str){
        vector<string> retorno;
        char*prin = strtok(linhas_str, "|");

        while(prin!=0){
            retorno.push_back(string(prin));
            prin = strtok(NULL, "|");
        }

        return retorno;
    }

    void CarregaTabela(string caminho){
        caminhoTabela = caminho;
        FILE* arq = fopen(caminho.c_str(), "r");
        if(arq == 0){
            throw "Arquivo não existe";
            exit(-1);
        }

        char titulosIni[1000];
        fscanf(arq, " %[^\n]", titulosIni);
        titulos = GeraLinhaParametros(titulosIni);
        int i = 0;
        while(*titulosIni = 0, fscanf(arq, " %[^\n]", titulosIni)!=-1){
           tabela[i++] = GeraLinhaParametros(titulosIni);
        }
        fclose(arq);
    }
private:
    string caminhoTabela;
    map<int, vector<string>> tabela;
    vector<string> titulos;
};

#endif // LOGICA_H
