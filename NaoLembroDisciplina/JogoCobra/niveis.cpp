#include "niveis.h"

int Niveis::nivelAtual = 1;
string Niveis::caminho = string(ARQ_NIVEIS);

void Niveis::proxNivel(){//realiza avanço para o proximo passo
    //ModoTexto::printPassouNivel(nivelAtual);
    _atualizaMapa();//atualiza os dados o mapa
    _atualizaJogador();
    if(nivelAtual>=5)Data::tempoPausa = Data::tempoPausa - 0.01;//aumenta velocidade da cobra
    nivelAtual++;
}

int Niveis::getNivelAtual()
{
    return nivelAtual;
}

string Niveis::getCaminho()
{
    return caminho;
}

void Niveis::_atualizaMapa(){
    string cam = caminho;
    cam[POS_ADD] += nivelAtual;
    FILE* arquivoMapa = fopen(cam.c_str(),"r");
    if(arquivoMapa==0){//o proximo nível não foi desenhado, manter mapa atual
        return;
    }
    int aux;
    for(int i=0;i<Mapa::getN();i++){
        for(int j=0;j<Mapa::getM();j++){
            fscanf(arquivoMapa,"%d",&aux);
            Mapa::setItemPosicaoMapa(aux,i,j);
        }
    }
    fclose(arquivoMapa);
}

void Niveis::_atualizaJogador(){//recomessa a cobra
    ItemMovel nova = *Data::jogador.getCabecaCobra();
    list<ItemMovel> cobra;//nova cobra
    nova.setX(11);nova.setY(8);
    cobra.push_back(nova);
    Data::jogador.setCobrinha(cobra);
}
