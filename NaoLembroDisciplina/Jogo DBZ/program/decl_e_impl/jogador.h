//class jogador
class jogador{
	private:
		animacao* sprites;
		bool orientacao_sprite;
	public:
		bool get_orientacao_sprite(){return orientacao_sprite;}
		BITMAP* acesso_stripe(int i,int j){return sprites->acesso_sprite(i,j);}
		BITMAP* acesso_sprite_power(int i){return sprites->acesso_sprite_power(i);}
		BITMAP* acesso_face(){return sprites->acesso_face();}
		void troca_orientacao();
		void set_x_y(int ,int);
		jogador(string,bool,int);
		~jogador(){delete sprites;}
		int get_x(){return x;}
		int get_y(){return y;}
		int num_sprites(int H){return sprites->num_sprites_anima(H); }
      int x,y;
};
