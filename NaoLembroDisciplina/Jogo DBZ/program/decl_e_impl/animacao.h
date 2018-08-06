//CLASS GRAFICA || ANIMAÇAO || MOVIMENTAÇAO
class animacao{
private:
   char pasta[100],caminho_imagens[NUM_ANIMA][200];
   int posi_seque[NUM_ANIMA],num_imagens[NUM_ANIMA],num_IMAGENS[MAX_IMAGENS];
   BITMAP *IMAGENS[NUM_ANIMA][MAX_IMAGENS];//lendo ok
   BITMAP *FACE;//lendo ok
   BITMAP *ESFERAS[NUM_ESFERAS_DRAGAO];//lendo ok
   BITMAP *KAME_POWER[3];//lendo ok
   void carrega_seque_sprites(int);
public:
   animacao(string,int);
   void carrega_imagens();
   BITMAP* acesso_sprite(int,int);
   BITMAP* acesso_sprite_power(int i){return KAME_POWER[i];}
   BITMAP* acesso_face();
   int num_sprites_anima(int H){return num_IMAGENS[H];}
};
 