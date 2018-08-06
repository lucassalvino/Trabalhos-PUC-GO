//FORMA DE DADOS // CLASS IMAGEM //CLASS MUSICA
//variaveis globais
int i,j,k,aux;
const char nome_imagens[NUM_ANIMA][15]={"PAR_00.pcx","PUL_00.pcx","LEV_00.pcx","DEF_00.pcx","CAI_00.pcx","ATAC_SE_00.pcx","ATAC_PR_00.pcx","AND_00.pcx"};
char PASTA_PERSONAGENS[NUM_PERSONAGENS][100]={"program/img/16","program/img/18","program/img/bils","program/img/cell","program/img/freza","program/img/gohan","program/img/goku","program/img/goku3","program/img/kuririm","program/img/mestre_kame","program/img/mr_satan","program/img/piculo","program/img/supremo_senhor_kaio","program/img/vegeta"};
int posi_cont[NUM_ANIMA]={5,5,5,5,5,9,9,5};

BITMAP *image_items[NUM_ITENS];
