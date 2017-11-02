#include "modotexto.h"


Par* ModoTexto::cobra = new Par(BRANCO,CONTORNO_VERMELHO);
Par* ModoTexto::grama = new Par(BRANCO,CONTORNO_VERDE);
Par* ModoTexto::parede = new Par(NORMAL,CONTORNO_ROCHO);
Par* ModoTexto::chao= new Par(BRANCO,CONTORNO_AMARELO);
Par* ModoTexto::alimento = new Par(BRANCO,CONTORNO_AZUL);
Par* ModoTexto::bonus = new Par(BRANCO,CONTORNO_VERMELHO);
Par* ModoTexto::jogador = new Par(BRANCO, CONTORNO_AZUL_CLARO);

void ModoTexto::printMapa(Mapa *mapa){
    if(mapa==0)throw string("IMPOSSIVEL CONTINUAR, PONTEIRO PARA MAPA INVALIDO.");
    for (int i=0;i<mapa->getN();i++){
        for(int j = 0;j<mapa->getM();j++){
            printCaracterMapa(mapa->getItemPosicaoMapa(i,j));
        }
        printf("\n");
    }
    CURSOR_OFF;
}

void ModoTexto::printMapa(int n, int m, int **mapa){
    if(mapa==0)throw string ("MATRIZ DO MAPA INVALIDO");
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printCaracterMapa(mapa[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<n;i++)
        delete [] mapa[i];
    delete [] mapa;
}

void ModoTexto::printJogador(Jogador *jogado, bool bonu){
    if(jogado==0)throw string("IMPOSSIVEL CONTINUAR. PONTEIRO PARA JOGADOR INVALIDO.");
    jogador->ativar();
    printf("%s\tPontos: %d\tMortes: %d\tRecorde: %d\tNivel: %d",jogado->getNome().c_str(),jogado->getPontuacao(),jogado->getNumeroMortes(),jogado->getRecorde(),Niveis::getNivelAtual());
    jogador->desativar();
    if (bonu){
        bonus->ativar();
        printf("\tBONUS");
        bonus->desativar();
    }
    printf("\n");
}

void ModoTexto::printMorte(int tamanho, ItemMovel posi)
{
    bonus->ativar();
    printf("VC MORREU");
    printf("\nTamanho da Cobra:%d",tamanho);
    printf("\nPosição da cabeça da cobra: %d - %d",posi.getX(),posi.getY());
    printf("\nDireção de movimento da cobra: ");
    if(posi.getDirecao()== DIREITA)
        printf("Direita");
    else
        if(posi.getDirecao()==ESQUERDA)
            printf("Esquerda");
        else
            if(posi.getDirecao()==BAIXO)
                printf("Baixo");
            else
                if(posi.getDirecao()==CIMA)
                    printf("Cima");
    printf("\nPresione ENTER");
    bonus->desativar();
    printf("\n");
}

void ModoTexto::printPassouNivel(int nivel){
    /*bonus->ativar();
    printf("VC PASSOU PARA O NIVEL: %d",nivel);
    bonus->desativar();*/
}

ModoTexto::~ModoTexto()
{
    delete cobra;
    delete grama;
    delete parede;
    delete chao;
    delete alimento;
    delete bonus;
    delete jogador;
}

void ModoTexto::printCaracterMapa(int val){
    switch (val) {
    case CAMINHO_CHAO:
        chao->ativar();
        printf(" ");
        chao->desativar();
        break;
    case CAMINHO_GRAMA:
        grama->ativar();
        printf("_");
        grama->desativar();
        break;
    case ALIMENTO:
        alimento->ativar();
        printf("0");
        alimento->desativar();
        break;
    case PAREDE:
        parede->ativar();
        printf(" ");
        parede->desativar();
        break;
    case COBRA:
        cobra->ativar();
        printf(" ");
        cobra->desativar();
        break;
    case CABECAC0BRA:
        cobra->ativar();
        printf(":");
        cobra->desativar();
        break;
    default:
        printf(" ");
        break;
    }
}

void Par::active_pair(int a){
    switch(a){
        case 0:{//RESETE
            printf("\033[0m");
            return;
            break;
        }
        case 1:{//NORMAL
            printf("\033[22m");
            return;
            break;
        }
        case 2:{//NEGRITO
            printf("\033[1m");
            return;
            break;
        }
        case 3:{//CINZA_CLARO
            printf("\033[2m");
            return;
            break;
        }
        case 4:{//SUBLINHADO
            printf("\033[4m");
            return;
            break;
        }
        case 5:{//NEGATIVO
            printf("\033[7m");
            return;
            break;
        }
        case 6:{//CINZA_CLARO_2
            printf("\033[30m");
            return;
            break;
        }
        case 7:{//VERMELHO
            printf("\033[31m");
            return;
            break;
        }
        case 8:{//VERDE
            printf("\033[32m");
            return;
            break;
        }
        case 9:{//AMARELO
            printf("\033[33m");
            return;
            break;
        }
        case 10:{//AZUL
            printf("\033[34m");
            return;
            break;
        }
        case 11:{//ROCHO
            printf("\033[35m");
            return;
            break;
        }
        case 12:{//AZUL_CLARO
            printf("\033[36m");
            return;
            break;
        }
        case 13:{//BRANCO
            printf("\033[37m");
            return;
            break;
        }
        case 14:{//CONTORNO_CINZA
            printf("\033[40m");
            return;
            break;
        }
        case 15:{//CONTORNO_VERMELHO
            printf("\033[41m");
            return;
            break;
        }
        case 16:{//CONTORNO_VERDE
            printf("\033[42m");
            return;
            break;
        }
        case 17:{//CONTORNO_AMARELO
            printf("\033[43m");
            return;
            break;
        }
        case 18:{//CONTORNO_AZUL
            printf("\033[44m");
            return;
            break;
        }
        case 19:{//CONTORNO_ROCHO
            printf("\033[45m");
            return;
            break;
        }
        case 20:{//CONTORNO_AZUL_CLARO
            printf("\033[46m");
            return;
            break;
        }
        case 21:{//CONTORNO_BRANCO
            printf("\033[47m");
            return;
            break;
        }
        case 22:{//CONTORNO_BRANCO
            return;
            break;
        }
        default:{//RESETE
            printf("\033[0m");
            return;
            break;
        }
    }
}
void Par::active_pair(int a,int b){
    active_pair(a);
    active_pair(b);
}
/////////////////////////////////////////////////////////////////////
void Par::gotoxy(int x,int y){
    printf("%c[%d;%df",0x1B,x,y);
}
