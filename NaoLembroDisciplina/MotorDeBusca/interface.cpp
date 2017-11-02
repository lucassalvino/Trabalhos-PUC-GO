#include "interface.h"
int StringToInt(string a){
    int soma=0,n=a.size();
    for(int i=0; i<n; i++){
        soma += a[i] +  (a[i]*(i*(1+n))) ;
    }
    soma = soma * n;
    return soma;
}
Interface::~Interface (){
    finalizar();
}

Tabelahash<string,PalavraDocumento> Interface::tabela;//pode usar o construtor
char* Interface::entrada;
Documento** Interface::arquivosTextos;
int Interface::numeroArquivos;
NoDoc<string,PalavraDocumento>* Interface::retorno=0;
int Interface::NumRetorno=0;
int Interface::NumBuscados=0;
Retorno* Interface::arquivosRetorno=0;
int Interface::numArquivosEnBusca=0;
float Interface::logNumeroArquivo;


void Interface::indexar(string arquivos){
    Interface::finalizar();//caso queira aproveitar as palavras já indexadas não chamar a função finalizar
    tabela.setFuncoesHash(StringToInt);
    entrada = stringToArrayChar(arquivos);
    FILE *arqEntrada = fopen(entrada,"r");
    if(arqEntrada == 0){
        throw (string("Arquivo de caminhos de\nentrada não existe"));
    }
    try{
        indexarArquivos(arqEntrada);
        fclose(arqEntrada);
    }
    catch(int erro){
        ExcecaoNaoTratada *oi= new ExcecaoNaoTratada(erro);
        oi->show();
    }
    catch (string erro){
        ExcecaoNaoTratada *oi= new ExcecaoNaoTratada(erro);
        oi->show();
    }
    catch (...){
        ExcecaoNaoTratada *oi= new ExcecaoNaoTratada("Erro não indexado, erro na indexação da tabela\n");
        oi->show();
    }
}

void Interface::indexarArquivos(FILE* entr){
    if(entr==0){
        throw(string("Ponteiro para arquivo invalido"));
    }
    fscanf(entr," %d",&numeroArquivos);
    if(numeroArquivos<1){
        throw(string("Arquivo com entrada anormal(n<1)\n"));
    }
    logNumeroArquivo = log10(numeroArquivos);
    arquivosTextos = new Documento*[numeroArquivos];
    int i;
    try{
        for(i=0;i<numeroArquivos;i++){
            char* caminho= new char[MAX_NOME_ARQUIVO];
            fscanf(entr," %s",caminho);
            indexarUmArquivo(caminho,i);
        }
        printf("\ntabela colisoes:%d\n",tabela.cont);
        for(i=0;i<numeroArquivos;i++){
            printf("\n\"%s\" possui %d palavras distintas\n",arquivosTextos[i]->getCaminho(),arquivosTextos[i]->getPalavrasDistintas());
        }
    }
    catch(int a){
        throw(a);
    }
    catch(string a){
        throw(a+"\n");
    }
    catch(...){
        throw("erro ao indexar o arquivo ");
    }
}

void Interface::indexarUmArquivo(char* caminho,int arqu){//indexa um arquivo
    FILE * arq = fopen(caminho,"r");
    if(arq==0){
        throw(string("Arquivo para indexar não existe"));
    }
    arquivosTextos[arqu] = new Documento(caminho);//ponteiros para todos os arquivos
    char ler[MAX_PALAVRA];
    while(*ler=0,fscanf(arq," %s",ler)!=EOF){
        try{
            trataPalavra(ler);//a partir da ki palavras ok
            string chave(ler);
            if(tabela.itemExiste(chave)){
                if(tabela.getIten(chave).arquivoExiste(caminho)){//arquivo já existe
                    PalavraDocumento help = tabela[chave];
                    help.getDocumentoPalavra(caminho)->incrementaNumeroVezesPalavra();
                    tabela.setIten(string(help.getPalavra()),help);
                }else{
                    DocumentoPalavra aux;
                    aux.setDocumento(arquivosTextos[arqu]);
                    aux.setNumeroVezesPalavra(1);
                    PalavraDocumento auxPala = tabela.getIten(chave);
                    auxPala.addArquivo(aux);
                    tabela.setIten(chave,auxPala);
                    arquivosTextos[arqu]->incrementaPalavrasDistintas();
                }
            }else{
                PalavraDocumento aux;
                DocumentoPalavra aux2;
                aux2.setDocumento(arquivosTextos[arqu]);
                aux2.setNumeroVezesPalavra(1);
                aux.setPalavra(ler);
                aux.addArquivo(aux2);
                tabela.setIten(chave,aux);
                arquivosTextos[arqu]->incrementaPalavrasDistintas();
            }
        }
        catch(int a){
            if(a==0){
                throw(string("Tabela hash cheia!ucg"));
                printf("parando de indexar o arquivo %s , tabela hash cheia\n",caminho);
                return;
            }
            printf("(erro: %d) palavra \"%s\" iguinorada\n",a,ler);
        }
        catch(...){
            printf("\nerro inesperado continuar\n");
        }
    }
}

char* Interface::stringToArrayChar(string no){
    int n=no.size(),i;
    char * a = new char[n+1];
    for(i=0;i<n;i++){
        a[i]=no[i];
    }
    a[i]='\0';
    return a;
}

void Interface::trataPalavra(char* pala){
    int i;
    for(i=0;pala[i]!='\0';i++){
        if(pala[i] >= 65 && pala[i] <= 90){
            pala[i]+=32;
        }
    }
    if(pala[0]<65 || pala[0]>122 || i<2){
        throw(-1);
    }
    i--;
    if(pala[i]<65 || pala[i]>122)
        pala[i]='\0';
}

int compare(Retorno p1, Retorno p2){//configurada para ordem crescente
    if(p1.getRelevancia() > p2.getRelevancia()) return -1;//primeiro maior que segundo retorna >0
    if(p1.getRelevancia() < p2.getRelevancia()) return 1;//primeiro menor que segundo retorna <0
    return 0;//caso seja igual retorn 0
}

void Interface::finalizar(){
    for(int i=0;i<numeroArquivos;i++){
        delete arquivosTextos[i];
    }
    delete [] arquivosTextos;
    delete [] entrada;
    delete [] retorno;
    delete [] arquivosRetorno;
    tabela.clean();
    tabela.inicializarTabela(tabela.getTamanhoTabela());
}

string Interface::buscarTermo(string termo,bool op){//bool caso true pelo menos uma palavra//caso false pelo todas
    string striRetorno="";
    delete [] arquivosRetorno;
    arquivosRetorno = 0;
    int i;
    if(tabela.size()==0)
        throw(string("Antes de buscar, indexe os arquivos."));
    buscaToPalavra(termo);
    for(i=0;i<NumRetorno;i++){
        if(tabela.itemExiste(retorno[i].getChave())){
            PalavraDocumento retoAux;
            retoAux = (tabela.getIten(retorno[i].getChave()));
            retorno[i].setDado(retoAux);
        }
    }
    NumBuscados = NumRetorno;
    organizaRetorno();//a partir da ki as palavras est~ao organizadas dentro de retorno[];
    if(NumBuscados != NumRetorno && !op){//impossivel fazer a busca de todos os termos, pois nem todos estao catalogados na tabela
        striRetorno += "impossivel fazer a busca de todos os termos! nem todos estao indexados\n";
        return striRetorno;
    }
    if(NumRetorno==0){
        striRetorno += "Nao existe nelhum dos termos que procuras!!\n";
        return striRetorno;
    }
    if(op || NumRetorno==1){//fazer união dos arquivos
        fazerUniao();
    }else{//fazer intersecção
        fazerInterseccao();
    }
    calcularRelevancia();
    //ordena decrescente
    heapSort(arquivosRetorno,numArquivosEnBusca,compare);
    //fazer somatorio da string com nome dos arquivos e pronto hahahahahahahahahahahahahaha
    for(i=0;i<numArquivosEnBusca;i++){
        striRetorno+= string(arquivosRetorno[i].getDocumentoRetorno()->getCaminho());
        striRetorno+= " -> relevancia:  " + QString::number(arquivosRetorno[i].getRelevancia()).toStdString();
        striRetorno+="\n";
    }
    return striRetorno;
}


void Interface::buscaToPalavra(string termo){
    int espacos=0,i,j;
    string a="";
    for(i=0;termo[i]!='\0';i++){
        if(termo[i] == ' ')
            espacos++;
    }
    char *pa = stringToArrayChar(termo);
    trataPalavra(pa);
    termo = string(pa);
    NumRetorno = espacos+1;
    retorno = new NoDoc<string,PalavraDocumento>[NumRetorno];
    for(i=0;i<NumRetorno;i++)retorno[i].setChave(string("777"));
    for(i=j=0;termo[i]!='\0';i++){
        if(termo[i]!=' ' && (termo[i]>=97 && termo[i] <= 122) ){
            a+=termo[i];
        }else
            if(termo[i]==' '){
                retorno[j++].setChave(a);
                a="";
            }
    }
    retorno[j].setChave(a);
}

void Interface::organizaRetorno(){
    int i,j;
    for(i=j=0;i<NumRetorno;i++){
        if(tabela.itemExiste(retorno[i].getChave())){
            retorno[j++]=retorno[i];
        }
    }
    NumRetorno=j;
    printf("\nForam encontradas %d palavras na busca\n",j);
    for(i=0;i<NumRetorno;i++){//adiciona palavra documento como dado no retorno
        retorno[i].setDado(tabela[retorno[i].getChave()]);
    }
    for(i=numArquivosEnBusca=0;i<NumRetorno;i++){
        numArquivosEnBusca+=retorno[i].getDado().getNumArquivos();
    }
    printf("Numero de arquivos encontradados %d \n",numArquivosEnBusca);
}


void Interface::calcularRelevancia(){
    int i,j;
    float rele;
    for(i=0;i<numArquivosEnBusca;i++){
        rele=0;
        int fij,dj;
        arquivosRetorno[i].setRelevancia(0);
        //calcular relevancia de cada arquivo a partir da ki
        for(j=0;j<NumRetorno;j++){
            DocumentoPalavra *oi = retorno[j].getDado().getDocumentoPalavra(arquivosRetorno[i].getDocumentoRetorno()->getCaminho());
            if(oi==0){
                fij=0;
            }else{
                fij = oi->getNumeroVezesPalavra();
            }
            dj = retorno[j].getDado().getNumArquivos();
            rele+=fij*(logNumeroArquivo/dj);
        }
        arquivosRetorno[i].setRelevancia((1.0/arquivosRetorno[i].getDocumentoRetorno()->getPalavrasDistintas())*rele);
        printf("Relevancia do arquivo %s  e : %f\n",arquivosRetorno[i].getDocumentoRetorno()->getCaminho(),arquivosRetorno[i].getRelevancia());
    }
}

void Interface::fazerUniao(){
    int i,j=0;//palavras estão em retorno
    arquivosRetorno = new Retorno[numArquivosEnBusca];//fazer união dos arquivos
    for(i=0;i<NumRetorno;i++){//passar de palavra em palavra
        DocumentoPalavra* lista = retorno[i].getDado().getVetorDocumentoPalavra();//em lista tenho todos os arquivos encontrados na palavra I
       int k,n = retorno[i].getDado().getNumArquivos();
        for(k=0;k<n;k++){//para cada documento da palavra i
            int cont=0;
            for(;cont<(j);cont++){//procurar se o arquivo k existe em arquivosRetorno
                if(strcmp(lista[k].getDocumento()->getCaminho(),arquivosRetorno[cont].getDocumentoRetorno()->getCaminho())==0){
                    break;
                }
            }
            if(cont==j){//foi até o final e não encotrou nada
                arquivosRetorno[j++].setDocumentoRetorno(lista[k].getDocumento());
            }
        }
        delete []lista;
    }
    numArquivosEnBusca = j;
    //união ok, os arquivos que contem as palavras estão em arquivosRetorno e são numArquivosEnBusca
}

void Interface::fazerInterseccao(){
    int i,j,k=0,n,selecionaPrimeiro=0;
    arquivosRetorno = new Retorno[numArquivosEnBusca];
    DocumentoPalavra** matrizBusca = new DocumentoPalavra*[NumRetorno];
    for(i=0;i<NumRetorno;i++){//
        matrizBusca[i] = retorno[i].getDado().getVetorDocumentoPalavra();
    }

    for(selecionaPrimeiro=0;selecionaPrimeiro < retorno[0].getDado().getNumArquivos() ; selecionaPrimeiro++){
        bool andei=false;
        for(i=1;i<NumRetorno;i++){
            n = retorno[i].getDado().getNumArquivos();
            for(j=0;j<n;j++){
                if(strcmp(matrizBusca[0][selecionaPrimeiro].getDocumento()->getCaminho(), matrizBusca[i][j].getDocumento()->getCaminho())==0){
                    andei=true;
                    break;
                }
            }
            if(andei)break;
        }
        if(andei){//andei tudo e achei o arquivo
            arquivosRetorno[k++].setDocumentoRetorno(matrizBusca[i][j].getDocumento());
        }
    }

    for(i=0;i<NumRetorno;i++){
        delete matrizBusca[i];
    }
    delete matrizBusca;
    numArquivosEnBusca = k;
}
