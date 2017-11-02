#include "interfacelogica.h"
bool InterfaceLogica::continuaThread = false;
bool InterfaceLogica::imprimirProxNivel = false;

void InterfaceLogica::andar(){
    //a partir da lista da cobra do jogador anda uma posicao de cada um
    list<ItemMovel>cobr = Data::jogador.getCobrina();//realiza o backup da cobra do jogador
    ItemMovel copia = *(cobr.begin());//copia contem a cabeça da cobra
    list<ItemMovel>::iterator iteratorCobra = cobr.begin();
    proxPosicao(*(iteratorCobra));
    for(iteratorCobra++;iteratorCobra!=cobr.end();iteratorCobra++){//para cada componente da cobra fazer ele andar uma posicao
        ItemMovel copiaAt = *(iteratorCobra);
        *(iteratorCobra) = copia;
        copia = copiaAt;
    }
    Data::jogador.setCobrinha(cobr);
}

void InterfaceLogica::virar(int direcao){
    //vira a cabeça da cobra para um direção
    if(direcao<DIREITA||direcao>BAIXO)throw string("DIRECAO INVALIDA");
    Data::jogador.getCabecaCobra()->setDirecao(direcao);
}

void InterfaceLogica::inicia(){//carrega arquivo de configuração e gera mapa
    FILE* conf = fopen(CONFIG,"r");
    if(conf == 0)throw string("Arquivo de Configuracao ["+string(CONFIG)+"] não Encontrado");
    int n,m;
    if(fscanf(conf," %d %d",&n,&m)<=0)throw string("Erro ao realizar a leitura de configurações!");
    Mapa::inicializaMapa(n,m);//inicializa o mapa com os todas as unidades limpas
    if(fscanf(conf,"%d",&Data::modoJogo)<=0)throw string("Erro ao carregar modo de jogo!");//carrega o modo de jogo
    fclose(conf);
    printf("CARREGADO MAPA %dX%d|| MODO  JOGO:: %d\n",n,m,Data::modoJogo);
}

bool InterfaceLogica::carregaJogador(){//carrega jogador salvo em arquivo, ou gera jogador padrõa
    try{
        Data::jogador.carregarJogadorArquivoTexto();
        return true;
    }
    catch(string erro){
        printf("[ERRO] %s\n",erro.c_str());
        return  false;
    }
    return false;
}

void InterfaceLogica::salvaJogador(){//salva o jogador atual no arquivo jogador.txt
    try{
        Data::jogador.salvaJogadorArquivo();
    }
    catch(string erro){
        printf("[DEBUG] ERRO: %s\n",erro.c_str());
    }
}

void InterfaceLogica::jogar(){
    switch (Data::modoJogo) {//verifica modo de jogo //modo texto||gráfico
    case 1://modo text
        _JogoModoTexto();//realiza o jogo em modo texto
        break;
    case 2://modo grafico
        break;
    default:
        break;
    }
}

void InterfaceLogica::carregaJogadorManual(){//le o nome do jogador em modo texto no terminal
    char nome [90];
    printf("Digite o nome do jogador: ");
    if(scanf(" %[^\n]",nome)<=0)throw string ("NÃO FOI POSSIVEL REALIZAR A LEITURA DO NOME.");
    Data::jogador.inicializaJogador(string(nome));
}

void InterfaceLogica::somatorioItem(int&x, int&y,pair<int,int>soma){//realiza a soma para andar uma posição, de acordo com os valores de soma, que deve conter os valores a serem somados para se andar uma posição de acordo com a direção
    x = (x+soma.first);
    y = (y+soma.second);
}

void InterfaceLogica::proxPosicao(ItemMovel &item){//move o item movel para uma posição à frende de acordo com a direção
    //move o item para a proxima posiçao a partir com base na sua direcao
    int x = item.getX();
    int y = item.getY();
    switch (item.getDirecao()) {
    case DIREITA:
        somatorioItem(x,y,Data::SOMATORIO_DIREITA);
        break;
    case ESQUERDA:
        somatorioItem(x,y,Data::SOMATORIO_ESQUERDA);
        break;
    case BAIXO:
        somatorioItem(x,y,Data::SOMATORIO_BAIXO);
        break;
    case CIMA:
        somatorioItem(x,y,Data::SOMATORIO_CIMA);
        break;
    default:
        throw string("VALOR INVALIDO");
        break;
    }
    validaPosicao(x,y);
    item.setX(x);
    item.setY(y);
}

void InterfaceLogica::_JogoModoTexto(){
    //realiza o jogo em modo texto
    if(Data::jogador.getNome() == "JogadorPadrao"){//caso não tenha conseguido carregar o arquivo do jogador, inicializa jogador aqui
        carregaJogadorManual();
    }
JOGO_MODO_TEXTO://se por acaso o jogador quiser parar, retonar a este marco
    continuaThread = true;
    try{
        thread leituraTeclado (__leituraTeclado);
        thread jogo (__jogo);
        thread avancaNi(__observerNivel);
        leituraTeclado.join();
        jogo.join();
        avancaNi.join();
    }
    catch (string erro){
        throw string("_JogoModoTexto: ")+erro;
    }
    if(imprimirProxNivel){
        imprimirProxNivel = false;
        //ModoTexto::printPassouNivel(Niveis::getNivelAtual());
        //Utilidades::pausa(2);
        goto JOGO_MODO_TEXTO;
    }
    if(!continuaThread){
        char ler[90];
        printf("JOGO PAUSADO\nDeseja sair (SIM || NAO)");if(scanf(" %[^\n]",ler)<=0)throw string ("Falha ao realizar leitura do teclado");
        if(string(ler)=="sim"||string(ler)=="SIM")return;
        else goto JOGO_MODO_TEXTO;//retorna ao laço principal do jogo
    }
}

void InterfaceLogica::validaPosicao(int &x, int &y){//verifica se a posicao x e y está dentro do mappar
    if(x<0) x = Mapa::getN()-1;
    if(y<0) y = Mapa::getM()-1;
    if(x>=Mapa::getN())x = 0;
    if(y>=Mapa::getM())y = 0;
}

int **InterfaceLogica::getMapaBuffer(){
    //monta a proxima exibição do mapa, junta os objetos do mapa alimentos e cobra
    int** reto =0;
    int n,m,i,j;
    n = Mapa::getN(); m = Mapa::getM();
    reto = new int* [n];
    if(reto==0)assert("MEMORIA INSUFICIENTE");
    for(i=0;i<n;i++){
        reto[i] = new int [m];
        if(reto[i]==0)assert("MEMORIA INSUFICIENTE");
    }
    for(i=0;i<n;i++){//copia o mapa para o mapaBuffer
        for(j=0;j<m;j++){
            reto[i][j] = Mapa::getItemPosicaoMapa(i,j);
        }
    }
    list<ItemMovel> cobra = Data::jogador.getCobrina();//copia cobra
    list<ItemMovel>::iterator it = cobra.begin();
    if (it == cobra.end())return reto;
    int x = it->getX(),y = it->getY();
    validaPosicao(x,y);
    reto[x][y] = CABECAC0BRA;
    for(it++;it!=cobra.end();it++){//coloca a cobra no mapabuffer//EXEÇAO SENDO LANCADA AQUI
        int x = it->getX(),y = it->getY();
        validaPosicao(x,y);
        reto[x][y] = COBRA;
    }
    if(Data::posiComida.first!=-1){//coloca o alimneto atual no mapa
        reto[Data::posiComida.first][Data::posiComida.second]=ALIMENTO;
    }
    if(Data::obstaculo.first!=-1){//coloca o obstaculo
        reto[Data::obstaculo.first][Data::obstaculo.second]=PAREDE;
    }
    return reto;
}

void InterfaceLogica::verificaComida(){//verifica se a comida existe, se não existir cria uma nova
    if(Data::posiComida.first==-1||(Mapa::getItemPosicaoMapa(Data::posiComida.first,Data::posiComida.second)>=PAREDE)){
        Data::posiComida.first = rand()%Mapa::getN();
        Data::posiComida.second = rand()%Mapa::getM();
        verificaComida();
    }
    return;
}

void InterfaceLogica::verificaAlimentacao(){//verifica se a cabeça da cobra está na mesma posica da comida, caso esteja a cobra come
    list<ItemMovel>::iterator cabecaCobra = Data::jogador.getCobrina().begin();
    if(cabecaCobra->getX() == Data::posiComida.first && cabecaCobra->getY() == Data::posiComida.second){
        int pontu = Data::obstaculo.first==-1?10:30;
        if(pontu==30)Data::obstaculo.first=-1;
        Data::jogador.addPontuacao(pontu);//caso obstaculos esteja visivel adiciona bonus
        Data::posiComida.first = -1;//criar comida novamente
        /*CRIAR NOVO NO COBRA*/
        Data::jogador.addNoCobrinha();
    }
}

void InterfaceLogica::verificaMorte(){//verifica se a cobrinha está em conformidade com as regras, para não estar morta
    list<ItemMovel> cobra = Data::jogador.getCobrina();
    ItemMovel cabe = *(cobra.begin());
    int mapaX = cabe.getX(), mapaY = cabe.getY();//posicao da cabeça da cobra
    if(Mapa::getItemPosicaoMapa(mapaX,mapaY)>=PAREDE){//se a posicao não é um obstaculo
        acoesMorte();
    }
    list<ItemMovel>::iterator it = cobra.begin();
    for(it++;it!=cobra.end();it++){//se a cobra não mordeu ela mesma
        if(cabe.getX() == it->getX() && cabe.getY() == it->getY()){
            acoesMorte();
        }
    }
    if(cabe.getX()==Data::obstaculo.first && cabe.getY()==Data::obstaculo.second){//obstaculo do bonus
        acoesMorte();
    }
}

void InterfaceLogica::morreu_Texto(){
    ModoTexto::printMorte(Data::jogador.getTamanho(),*Data::jogador.getCabecaCobra());
}

void InterfaceLogica::verificaObstaculo(){
    //verifica se o bonus foi ativado, caso sim, habilitar obstaculo
    if(Data::jogador.getPontuacao()%50==0 &&Data::jogador.getPontuacao()!=0){//caso seja multiplo de 50
        if(Data::obstaculo.first==-1){
            Data::obstaculo.first = rand()%Mapa::getN();
            Data::obstaculo.second = rand()%Mapa::getM();
        }
    }
}

void InterfaceLogica::acoesMorte()
{//acoes a serem feitas quando o jogador morrer
    continuaThread = false;
    morreu_Texto();
    Data::jogador.morteJogador();
    Data::obstaculo.first = -1;
}

void InterfaceLogica::__leituraTeclado(){
    try{
        while (continuaThread)
           processaLeituraTeclado(Utilidades::getch());
    }
    catch(int erro){throw erro;}
}

void InterfaceLogica::__jogo()
{
    while(continuaThread){//laço principal do jogo em modo texto
        ModoTexto::printJogador(&Data::jogador,Data::obstaculo.first==-1?false:true);//imprimi linha de cima com os dados dos jogadores
        ModoTexto::printMapa(Mapa::getN(),Mapa::getM(),getMapaBuffer());//imprime o mapa, getMapaBuffer retorna uma string com o mapa
        verificaComida();//verifica se a comida está disponível no mapar
        //processaLeituraTeclado(getch());//realiza leitura do teclado
        andar();//anda uma posição da cobrinha
        verificaMorte();//verifica estado do jogador, ou seja, se o ultimo movimento do jogodor não matou
        verificaAlimentacao();//se o cara não morreu, verifica se ele conseguiu comer
        verificaObstaculo();//verifica se existe obstaculos, aparece somente quando a pontuação atinge multiplos de 50
        Utilidades::pausa(Data::tempoPausa);//pausa de 0.001 segundos
    }
}

void InterfaceLogica::__observerNivel(){
    while(continuaThread){
        imprimirProxNivel = AvancarNivel::analisaDados();
        if (imprimirProxNivel)continuaThread = false;
    }
}

void InterfaceLogica::processaLeituraTeclado(char leitura){//recebe o ultimo caracter digitado pelo teclado e realiza as ações correspondentes
    if(leitura>='A'&&leitura<='Z'){//caso o valor esteja no em maiusculo, colocar em minusculo
        leitura += 32;//na tabela ASCII, as letra minusuculas estao 32 valores à frente das maiusculas
    }
    switch (leitura) {
    case 'w':
        virar(CIMA);
        break;
    case 's':
        virar(BAIXO);
        break;
    case 'd':
        virar(DIREITA);
        break;
    case 'a':
        virar(ESQUERDA);
        break;
    case 'q'://finaliza jogatina
        continuaThread = false;
        break;
    default:
        break;
    }
}
