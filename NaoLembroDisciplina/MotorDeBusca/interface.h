#ifndef INTERFACE_H
#define INTERFACE_H
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
#include "excecaonaotratada.h"
#include <tabelahash.hpp>
#include <documentopalavra.h>
#include "palavradocumento.h"
#include "documento.h"
#include "retorno.h"
#include "ordenar.h"
/*class cumunicar entre grafica e logica*/
class Interface
{
public:
    static void indexar(string);
    static char* stringToArrayChar(string);
    static string buscarTermo(string,bool);//bool caso true todas palavras//caso false pelo menos uma
    inline static char* caminhoEntraga(){return entrada;}
    static void finalizar();
    ~Interface ();
private:
    static Tabelahash<string,PalavraDocumento> tabela;
    static char* entrada;
    static Documento** arquivosTextos;
    static int numeroArquivos;
    static float logNumeroArquivo;
    static NoDoc<string,PalavraDocumento>* retorno;
    static int NumRetorno;//numero de palavras que existem indexadas na tabela
    static int NumBuscados;//numero de palavras buscadas
    static Retorno* arquivosRetorno;
    static int numArquivosEnBusca;


    static void organizaRetorno();
    static void calcularRelevancia();
    static void indexarArquivos(FILE*);
    static void indexarUmArquivo(char*,int);
    static void trataPalavra(char*);
    static void buscaToPalavra(string);
    static void fazerUniao();
    static void fazerInterseccao();
};
#endif // INTERFACE_H
