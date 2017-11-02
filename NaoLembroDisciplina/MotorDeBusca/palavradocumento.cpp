#include "palavradocumento.h"

bool PalavraDocumento::arquivoExiste(char * nome){
    list<DocumentoPalavra>::iterator it;
    for(it = documentoPalavra.begin(); it!=documentoPalavra.end(); it++){
        if(strcmp(nome , it->getDocumento()->getCaminho())==0){
            return true;
        }
    }
    return false;
}

void PalavraDocumento::addArquivo(DocumentoPalavra docPa){
    documentoPalavra.push_back(docPa);
}

DocumentoPalavra* PalavraDocumento::getDocumentoPalavra(char* nome){
    if(arquivoExiste(nome)){
        list<DocumentoPalavra>::iterator it;
        for(it = documentoPalavra.begin(); it!=documentoPalavra.end(); it++){
            if(strcmp(nome , it->getDocumento()->getCaminho())==0){
                return &*it;
            }
        }
    }
    return 0;
}
int PalavraDocumento::getNumArquivos(){
    return documentoPalavra.size();
}

void PalavraDocumento::setPalavra(char* palavra){
    strcpy(this->palavra,palavra);
}

char* PalavraDocumento::getPalavra(){
    return this->palavra;
}
DocumentoPalavra* PalavraDocumento::getVetorDocumentoPalavra(){
    DocumentoPalavra *aux=new DocumentoPalavra[documentoPalavra.size()];
    list<DocumentoPalavra>::iterator it;
    int i=0;
    for(it = documentoPalavra.begin(); it!=documentoPalavra.end(); it++){
       aux[i++]= *it;
    }
    return aux;
}
