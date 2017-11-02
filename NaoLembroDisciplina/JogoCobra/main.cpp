#include <iostream>
#include <stdlib.h>
#include "mapa.h"
#include "jogador.h"
#include "interfacelogica.h"



#include <limits.h>
using namespace std;

int main(){
    try{
        InterfaceLogica::inicia();
        if(system("clear")<0)throw string ("Erro ao realizar chamada ao sistema.");
        !InterfaceLogica::carregaJogador();
        InterfaceLogica::jogar();
        InterfaceLogica::salvaJogador();
    }
    catch(string erro){
        printf("ERRO-> [%s]\n",erro.c_str());
    }
    catch(...){
        printf("A NUM SEI O QUE ACONTECEU");
    }
    cout << "BAY" << endl;
    return 0;
}
