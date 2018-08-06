//vida.cpp
#include"vida.h"
//quando maior o valor da destreza mais lento será os golpes primérios efetuados pelo jogador quanto maior mais lento será os ataques
//vida || destreza || esferas || energia 
Vida::Vida(){
	set_vida(MAX_VIDA);
	set_destreza(DESTREZA_INICIAL);
	set_esferas(0);
	set_energia(ENERGIA_INICIAL);
	set_forca(FORCA_INICIAL);//10
	set_defende(false);
	limpa_bau();
}
Humano::Humano(){
	set_vida(MAX_VIDA);
	set_destreza(DESTREZA_INICIAL-1);
	set_esferas(0);
	set_energia(ENERGIA_INICIAL-5);
	set_forca(FORCA_INICIAL*0.0000009);//90
	set_defende(false);
	limpa_bau();
}
Sayadim::Sayadim(){
	set_vida(MAX_VIDA);
	set_destreza(DESTREZA_INICIAL-1);
	set_esferas(0);
	set_energia(ENERGIA_INICIAL);
	set_forca(FORCA_INICIAL*0.000001);//100
	set_defende(false);
	limpa_bau(); 
}
Freza::Freza(){
	set_vida(MAX_VIDA);
	set_destreza(DESTREZA_INICIAL-2);
	set_esferas(0);
	set_energia(ENERGIA_INICIAL+10);
	set_forca(FORCA_INICIAL*0.000009);//900
	set_defende(false);
	limpa_bau();
}
Super_Sayadim::Super_Sayadim(){
	set_vida(MAX_VIDA);
	set_destreza(DESTREZA_INICIAL-2);
	set_esferas(0);
	set_energia(ENERGIA_INICIAL+10);
	set_forca(FORCA_INICIAL*0.00001);//1000
	set_defende(false);
	limpa_bau();
}
Super_Sayadim_2::Super_Sayadim_2(){
	set_vida(MAX_VIDA);
	set_destreza(DESTREZA_INICIAL-2);
	set_esferas(0);
	set_energia(ENERGIA_INICIAL+20);
	set_forca(FORCA_INICIAL*0.00003);//2000
	set_defende(false);
	limpa_bau();
}
Super_Sayadim_3::Super_Sayadim_3(){
	set_vida(MAX_VIDA);
	set_destreza(DESTREZA_INICIAL-3);
	set_esferas(0);
	set_energia(ENERGIA_INICIAL+40);
	set_forca(FORCA_INICIAL*0.00009);//6000
	set_defende(false);
	limpa_bau();
}
Deus_da_distruicao::Deus_da_distruicao(){
	set_vida(MAX_VIDA);
	set_destreza(DESTREZA_INICIAL-3);
	set_esferas(0);
	set_energia(100);
	set_forca(FORCA_INICIAL*0.0001);//10000
	set_defende(false);
	limpa_bau();
}
Seres_Supremos::Seres_Supremos(){
	set_vida(MAX_VIDA);
	set_destreza(DESTREZA_INICIAL-2);
	set_esferas(0);
	set_energia(ENERGIA_INICIAL+5);
	set_forca(FORCA_INICIAL*0.00001);//10 000
	set_defende(false);
	limpa_bau();
} 
Picculo::Picculo(){
	set_vida(MAX_VIDA);
	set_destreza(DESTREZA_INICIAL-1);
	set_esferas(0);
	set_energia(ENERGIA_INICIAL-3);
	set_forca(FORCA_INICIAL*0.000008);//800
	set_defende(false);
	limpa_bau();
}
Androide::Androide(){
	set_vida(MAX_VIDA);
	set_destreza(DESTREZA_INICIAL-1);
	set_esferas(0);
	set_energia(ENERGIA_INICIAL-3);
	set_forca(FORCA_INICIAL*0.000008);//800
	set_defende(false);
	limpa_bau();
}


void Vida::set_energia(int a){
	if(a<0){
		energia=0;
		return;
	}
	if(a>MAX_ENERGIA){
		energia=MAX_ENERGIA;
		return;
	}
	energia=a;
	return;
}
void Vida::realizar_desejo(){
	vida=MAX_VIDA;
	energia=MAX_ENERGIA;
	aumentar_destreza();
	aumentar_destreza();
}
void Vida::recupera_vida(int a){
	vida+=a;
	if(vida>MAX_VIDA)vida=MAX_VIDA;
}
int Vida::realizar_ataque_primario(){//esse ta ok
	if(consegue_realizar_ataque()){
		energia-=1;//penalidade por ter feito ataque
		return (int)1+(forca*0.01);
	}
	else
		return 0;
}
int Vida::realizar_ataque_secundario(){
	if(consegue_realizar_ataque()){
		energia-=1;
		return (int)(forca*0.05);
	}else{
		return 0;
	}
}
int realizar_ataque_secundario();
bool Vida::levar_dano(int a){
	int vida_ant=vida;
	if(defende&&energia){
		int aux=energia/10;
		aux+=forca*0.05;//5 por cento para defeza
		set_energia(energia-2);
		if(aux>=a){return false;}//consegue defender
		if (a-aux>50)vida -= 50;
		else vida-=(a-aux);
		if(vida<0)vida=0;
	}else{//ok
		int b;
		b=energia/10;
		b+=forca*0.01;//1 por cento
		if(b>=a){//consegue defender
			vida-=1;
		}else{
			vida-=(a-b);//dano realmente
		}
		if(vida<0)vida=0;
	}
	if(vida_ant-vida>=30){
		return true;
	}
	return false;
}
void Vida::novo_item(bool chet){
	srand(time(NULL));
	int a=(rand()%NUM_ITENS);
	delete bau;
	if(chet){
		bau=new Item_lua_cheia();
	}else
	switch(a){
		case NADA:{
			bau=new Item_void();
			break;
		}
		case CASCO_TARTARUGA:{
			bau= new Item_casco_tartaruga();
			break;
		}
		case ESPADA:{
			bau= new Item_espada();
			break;
		}
		case LUA_CHEIA:{
			bau=new Item_lua_cheia();
			break;
		}
		case MESTRE_KAME:{
			bau= new Item_mestre_kame();
			break;
		}
		case NUVEM_VOADORA:{
			bau = new Item_nuvem_voadora();
			break;
		}
		case PEIXE:{
			bau =new Item_peixe();
			break;
		}
		case SEMENTE_DOS_DEUSES:{
			bau = new Item_semente_dos_deuses();
			break;
		}
		case SENHOR_KAIO:{
			bau = new  Item_senhor_kaio();
			break;
		}
		case ZENI:{
			bau = new Item_zeni();
			break;
		}
		case TITI:{
			bau = new Item_titi(); 
			break;
		}
		case BULMA:{
			bau = new Item_bulma();
			break;
		}
		case LANCHI:{
			bau = new Item_lanchi();
			break;
		}
		case BABIDI:{
			bau = new Item_babidi();
			break;
		}
		case CELL:{
			bau = new Item_cell();
			break;
		}
	}

	if(!bau->dano){
		set_vida(bau->vida_i);
		set_destreza(destreza+bau->destreza_i);
		set_energia(energia+bau->energia_i);
		set_forca(forca+bau->forca_i);
	}else{
		levar_dano(bau->vida_i);
		energia-=bau->energia_i;
		if(energia<0)energia=0;
	}
}
void Vida::limpa_bau(){
	bau=new Item_void();
}
void Vida::set_vida(int a){
	vida+=a;
	if(vida>MAX_VIDA)vida=MAX_VIDA;
	else
		if(vida<0)vida=0;
}