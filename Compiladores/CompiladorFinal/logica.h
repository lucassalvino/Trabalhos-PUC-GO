#ifndef LOGICA_H
#define LOGICA_H
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <map>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;
class Logica
{
public:
    Logica(){
        pilha.push(0);
        entrada.push("$");
    }

    vector<string> getTitulos(){ return titulos;}
    vector<string> getLinhaTabela(int index){return tabela[index];}
    int numeroLinhas(){return (int)tabela.size();}
    vector<string> GeraLinhaParametros(char* linhas_str){
        vector<string> retorno;
        char*prin = strtok(linhas_str, "|");

        while(prin!=0){
            string pla = string(prin);
            retorno.push_back(pla == "."?"":pla);
            prin = strtok(NULL, "|");
        }
        return retorno;
    }

    void CarregaTabela(string caminho){
        int n = 0;
        caminhoTabela = caminho;
        FILE* arq = fopen(caminho.c_str(), "r");
        if(arq == 0){
            throw "Arquivo não existe";
            exit(-1);
        }
        fscanf(arq, "%d", &n);
        char producao_str[5000];
        for(int i = 0; i< n; i++){
            *producao_str = 0;
            fscanf(arq, " %[^\n]", producao_str);
            producoes.push_back(string(producao_str));
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
    void calculaProximoPasso(){
        int colunaPilha = GetColunaTitulo(entrada.top());

        if(colunaPilha < 0){
            throw string("falha, entrada ["+ entrada.top()+ "] nao foi indexada.");
        }

        string entradaLinha = tabela[pilha.top()][colunaPilha];

        if(entradaLinha == ""){
            throw string("falha não encontrado ação para o topo da pilha e a entrada especificada");
        }

        if(entradaLinha[0] == 'S' || entradaLinha[0] == 's' ){
            std::remove(entradaLinha.begin(), entradaLinha.end(), 's');
            std::remove(entradaLinha.begin(), entradaLinha.end(), 'S');
            int num = std::stoi(entradaLinha);
            pilha.push(num);
        }else{
            if(entradaLinha[0] == 'R' || entradaLinha[0] == 'r' ){
                std::remove(entradaLinha.begin(), entradaLinha.end(), 'R');
                std::remove(entradaLinha.begin(), entradaLinha.end(), 'r');
                int num = std::stoi(entradaLinha);
                string producao = producoes[num];
                int numeroReduce = GetNumeroRemocoesPilha(producao);

                for(;numeroReduce; numeroReduce--)
                    pilha.pop();

                num = pilha.top();
                string reduz = std::stoi(producoes[num][0]);
                int num2 = GetColunaTitulo(reduz);
                string tabela = tabela[num][num2];
                pilha.push(std::stoi(tabela));
            }
        }
    }
private:
    string caminhoTabela;

    map<int, vector<string>> tabela;
    vector<string> titulos;
    vector<string> producoes;

    int passo;
    stack<int> pilha;
    stack<string> entrada;
    string acoa;


    int GetColunaTitulo(string entrada){
        int i;
        for(i = 0 ; i < (int)titulos.size(); i++){
            if(entrada == titulos[i]) return i;
        }
        return -1;
    }


    int GetNumeroRemocoesPilha(string producao){
        producao = trim(producao);
        char antes[50], depois[100];
        sscanf(producao.c_str(), "%[^>]> %s", antes, depois);
        int reto = 0;
        for(int i = 0; depois[i] != '\0'; i++)
            if(depois[i] == ' ')
                reto ++;
        return ++reto;
    }


    std::string& ltrim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
    {
        str.erase(0, str.find_first_not_of(chars));
        return str;
    }

    std::string& rtrim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
    {
        str.erase(str.find_last_not_of(chars) + 1);
        return str;
    }

    std::string& trim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
    {
        return ltrim(rtrim(str, chars), chars);
    }
};

/*
S' -> S
S -> E;A
S -> A
A -> I
A -> E
I -> if E then S else S
E -> E + T
E -> F
E -> ( E )
T -> T * F
*/
#endif // LOGICA_H
