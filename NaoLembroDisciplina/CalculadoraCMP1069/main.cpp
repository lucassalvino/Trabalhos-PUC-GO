#include <iostream>
#include "operadores.hpp"
#include <stdlib.h>

using namespace std;

#define CLEAR "clear"
//#define CLEAR "cls"

#define ERRO_FATAL 13
char imprimeOpcoesPrincipais();
void leituraAeB(double&a , double&b);
bool desejaContinuar(string pergunta);
bool validaNum(string num);

int main(void)
{
    try{
        while(true){//laço principal de iteracao com o usuario
            system(CLEAR);
            char opcao = imprimeOpcoesPrincipais();//imprime as opções possíveis para o usuario. E retorna a opção selecionado pelo mesmo
            if(opcao == 'S'||opcao == 's')break;//caso o usuario queira sair, para o laço principal de iteração com o usuário
            double a,b,resultado;
            leituraAeB(a,b);//realiza leitura das variaveis da operação
            switch (opcao) {
            case '+':
                resultado = Operadores<double>::somar(a,b);
                break;
            case '-':
                resultado = Operadores<double>::subtrair(a,b);
                break;
            case '/':
                resultado = Operadores<double>::dividir(a,b);
                break;
            case '*':
                resultado = Operadores<double>::multiplicar(a,b);
                break;
            case '^':
                resultado = Operadores<double>::potencia(a,b);
                break;
            default:
                throw ERRO_FATAL;//POSSIVEL ALTERAÇÃO DA FUNCAO IMPRIMEOPCOESPRINCIPAIS
            }
            printf("\nResultado = %.3lf\n",resultado);
            if(!desejaContinuar(string("Deseja realizar outra Operação?")))break;
        }
    }
    catch(string erro){//erros esperados são do tipo String. Imprimir mensagem com erro e solicitar decisão ao usuario
        printf("ERRO: [%s].\n",erro.c_str());
        if(desejaContinuar("Deseja realizar outra operação?")){
            return main();
        }
    }
    catch(...){//caso seja lançada uma exceção não esperada, finalizar a execução do programa
        assert(true);
    }

    printf("ATÉ MAIS!\n");
    return 0;
}


char imprimeOpcoesPrincipais(){
    //imprime as principais funções disponíveis para o usuário
    try{
        char opcao;
        printf("Digite uma das opções abaixo:\n");
        printf("+ -> realizar adição: a+b\n");
        printf("- -> realizar subtração: a-b\n");
        printf("/ -> realizar divisão: a/b\n");
        printf("* -> realizar multiplicação: a*b\n");
        printf("^ -> realiza a potenciação: a^b\n");
        printf("S -> Terminar a execução do programa.\n");
        scanf(" %c",&opcao);
        if(opcao=='+'||opcao=='-'||opcao=='/'||opcao=='*'||opcao=='^'||opcao=='S'||opcao=='s')return opcao;
        else throw 0;
    }
    catch(int a){
        if (a==0){
            system(CLEAR);
            printf("Você digitou um valor invalido. Por favor realize a operação novamente!!!!\n");
            return imprimeOpcoesPrincipais();
        }
        else throw(a);
    }
    catch(...){
        throw ERRO_FATAL;//erro inesperado ocorreu.
    }
    return ' ';
}

void leituraAeB(double&a , double&b){
    //recebe a referencia das variaveia a e b e realiza a leitura de valores de dupla precisao para a e b
    try{
        char charA[90];
        char charB[90];
        printf("\nDigite o valor de A: ");scanf(" %s",charA);//leitura de um 'numero' em um char para validacao
        if(validaNum(string(charA)))sscanf(charA,"%lf",&a);//caso o numero seja valido realizo a leitura da string para o double
        else throw string("Valor não é numerico");
        printf("\nDigite o valor de B: ");scanf(" %s",charB);//leitura de um 'numero' em um char para validacao
        if(validaNum(string(charB)))sscanf(charB,"%lf",&b);//caso o numero seja valido realizo a leitura da string para o double
        else throw string("Valor não é numerico");
    }
    catch(string erro){
        printf("%s",erro.c_str());
        if(desejaContinuar("Deseja ler novamente?")) return leituraAeB(a,b);
    }
}

bool desejaContinuar(string pergunta){
    //realisa a pergunda para o usuario, a pergunta deve possuir apenas resposta booleana
    char resposta;
    printf("%s\n",pergunta.c_str());
    printf("Digite S para SIM ou N para Não:");scanf(" %c",&resposta);
    if(resposta=='S'||resposta=='s')return true;
    if(resposta=='N'||resposta=='n')return false;
    printf("Você digitou um valor incorreto, por favor digite novamente.");
    return desejaContinuar(pergunta);
}

bool validaNum(string num){
    /*recebe uma string e valida se a mesma está em um estado aceitavel para o ser usado em uma operacao. O numero possui apenas numeros
    o unico caracter aceitavel, é o '.' que deve aparecer somente uma vez*/
    int contPonto=0;
    for(int i=0; i<(int)num.size(); i++){
        if((num[i]<'0'||num[i]>'9')){
            if(num[i]=='.')contPonto++;
            if(num[i]!='.' || contPonto>1)return false;
        }
    }
    return true;
    printf("Alteração 01 em master")
}