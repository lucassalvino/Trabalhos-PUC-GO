//vida.h
class Vida{
	private:
		int vida,destreza,energia,forca,esferas;
		bool defende;
		Item *bau;
	public:
		void save_file();
		string load_file();
		Vida();
		inline int get_vida(){return vida;}
		inline int get_destreza(){return destreza;}
		inline int get_esteras(){return esferas;}
		inline int get_energia(){return energia;}
		inline int get_forca(){return forca;}
		inline bool get_defende(){return defende;}

		inline void set_defende(bool a){defende=a;}
		inline void set_destreza(int a){destreza=a;}
		inline void set_esferas(int a){esferas=a;}
		inline void set_forca(int a){forca=a;}
		inline int item_bau(){return bau->item;}
		void set_energia(int);

		void set_vida(int a);
		void recupera_vida(int a);
		void realizar_desejo();
		int realizar_ataque_primario();
		int realizar_ataque_secundario();
		void novo_item(bool);
		void limpa_bau();
		bool levar_dano(int a);
		inline bool consegue_realizar_ataque(){return energia>0;}
		inline bool esta_vivo(){return vida>0;}
		inline void aumentar_destreza(){destreza-=DECREMENTO_DESTREZA;}
		inline void diminuir_destreza(){destreza+=DECREMENTO_DESTREZA;}
};
class Humano: public Vida{
	public:
		Humano();
};
class Freza:public Vida{
	public:
		Freza();
};
class Sayadim: public Vida{
	public:
		Sayadim();
};
class Super_Sayadim: public Vida{
	public:
		Super_Sayadim();
};
class Super_Sayadim_2: public Vida{
	public:
		Super_Sayadim_2();
};
class Super_Sayadim_3: public Vida{
	public:
		Super_Sayadim_3();
};
class Deus_da_distruicao: public Vida{
	public:
		Deus_da_distruicao();
};
class Seres_Supremos: public Vida{
	public:
		Seres_Supremos();
};
class Picculo:public Vida{
	public:
		Picculo();
};
class Androide:public Vida{
	public:
		Androide();
};