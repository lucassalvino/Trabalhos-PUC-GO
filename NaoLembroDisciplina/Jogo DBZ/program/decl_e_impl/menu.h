#define DIS_CENTRA 150
#define NUM_MUSICAS 9
 SAMPLE * musica[NUM_MUSICAS];
 int tocar,tocando_1=0;
struct pos_menu{
	int x,y;   		
};
pos_menu pos_faces[NUM_PERSONAGENS];
pos_menu pos_fundo[NUM_FUNDOS];
BITMAP * selecao[2];
int ale[3]={0};//digitar ale
bool alea=false;
int contador=0,tim=100;
bool valida_tra(int a){
	for(int i=0;i<3;i++)
		if(ale[i]!=a)return false;
	return true;
}
bool trapaca=0;
SAMPLE *trapa;
int Interface::menu(){
	//text_mode(15);
	load_personagens();
	trapa=load_sample("program/sond/fundo_trapassa.wav");
	musica[0]=load_sample("program/sond/fundo_musica.wav");
	musica[1]=load_sample("program/sond/fundo_musica_1.wav");
	musica[2]=load_sample("program/sond/fundo_musica_2.wav");
	musica[3]=load_sample("program/sond/fundo_musica_3.wav");
	musica[4]=load_sample("program/sond/fundo_musica_4.wav");
	musica[5]=load_sample("program/sond/fundo_musica_5.wav");
	musica[6]=load_sample("program/sond/fundo_musica_6.wav");
	musica[7]=load_sample("program/sond/fundo_musica_7.wav");
	musica[8]=load_sample("program/sond/fundo_musica_8.wav");


	int i,j,ganha[2];ganha[0]=ganha[1]=0;
	int pos_1=0,pos_2=7,pos_3=0,aux;
	while(!key[KEY_ESC]){
		//text_mode(-1);
		//textprintf(screen, font, 400, 100, 15, "Pontos: %d", 5);
		if(!tocando_1){
			tocar=rand()%NUM_MUSICAS;
			play_sample(musica[tocar], 255, 127, 1000, 1 );
			tocando_1=1;
		}
		contador++;
		draw_sprite(screen,fundo_menu,0,0);
		draw_sprite(screen,quadro,140,0);
		for(i=0;i<NUM_PERSONAGENS/2;i++){draw_sprite(screen,faces[i],i*72+(i*3)+DIS_CENTRA,10);}
		for(j=0;i<NUM_PERSONAGENS;i++,j++){draw_sprite(screen,faces[i],j*72+(j*3)+DIS_CENTRA,95);}
		draw_sprite(screen,selecao[0],pos_faces[pos_1].x,pos_faces[pos_1].y);
		draw_sprite(screen,selecao[1],pos_faces[pos_2].x,pos_faces[pos_2].y);
		fflush(stdin);
		if(key[KEY_A])ale[0]=1;
		if(key[KEY_L])ale[1]=1;
		if(key[KEY_E])ale[2]=1;
		if(key[KEY_T])ale[0]=2;
		if(key[KEY_O])ale[1]=2;
		if(key[KEY_C])ale[2]=2;
		if(key[KEY_P]){
			if(tocando_1){
				stop_sample(musica[tocar]);
				stop_sample(trapa);
				trapaca=false;
			}else{
				tocando_1=false;
			}
		}
		if(valida_tra(1)){alea=true;ale[0]=ale[1]=ale[2]=0;}
		if(key[KEY_DEL]&&trapaca){
			trapaca=false;
			stop_sample(trapa);
			tocando_1=false;
			alea=false;
			ale[0]=ale[1]=ale[2]=0;
		}
		if(!trapaca&&valida_tra(2)){
			stop_sample(musica[tocar]);
			play_sample(trapa,255,127,1000,1);
			trapaca=true;ale[0]=ale[1]=ale[2]=0;
		}
		if(key[KEY_9]&&!trapaca){
			stop_sample(musica[tocar]);
			tocar++;
			if(tocar==NUM_MUSICAS)tocar=0;
			play_sample(musica[tocar],255,127,1000,1);
		}
		if(key[KEY_8]&&!trapaca){
			stop_sample(musica[tocar]);
			tocar--;
			if(tocar<0)tocar=NUM_MUSICAS-1;
			play_sample(musica[tocar],255,127,1000,1);
		}
		switch(movimenta_1()){
			case PRESS_D:
				pos_1++;
				if(pos_1>=NUM_PERSONAGENS)pos_1=0;
				break;
			case PRESS_A:
				pos_1--;
				if(pos_1<0)pos_1=NUM_PERSONAGENS-1;
				break;
			case PRESS_W:
				if(pos_1<=6)pos_1+=7;
				else pos_1-=7;
				break;
			case PRESS_S:
				if(pos_1<=6)pos_1+=7;
				else pos_1-=7;
				break;
		}
		fflush(stdin);
		switch(movimenta_2()){
			case PRESS_D:
				pos_2++;
				if(pos_2>=NUM_PERSONAGENS)pos_2=0;
				break;
			case PRESS_A:
				pos_2--;
				if(pos_2<0)pos_2=NUM_PERSONAGENS-1;
				break;
			case PRESS_W:
				if(pos_2<=6)pos_2+=7;
				else pos_2-=7;
				break;
			case PRESS_S:
				if(pos_2<=6)pos_2+=7;
				else pos_2-=7;
				break;
		}
		if(key[KEY_ENTER]||alea){
   			select_personagem(pos_1,0);
   			select_personagem(pos_2,1);
   			inicializa_sprites_gerais();
   			delay(0.5);
   			while(!key[KEY_ESC]||alea){
   				draw_sprite(screen,fundo_menu,0,0);
				draw_sprite(screen,quadro,140,0);
				for(i=0;i<NUM_PERSONAGENS/2;i++){draw_sprite(screen,faces[i],i*72+(i*3)+DIS_CENTRA,10);}
				for(j=0;i<NUM_PERSONAGENS;i++,j++){draw_sprite(screen,faces[i],j*72+(j*3)+DIS_CENTRA,95);}
				draw_sprite(screen,selecao[0],pos_faces[pos_1].x,pos_faces[pos_1].y);
				draw_sprite(screen,selecao[1],pos_faces[pos_2].x,pos_faces[pos_2].y);
   				for(i=0;i<NUM_FUNDOS;i++)draw_sprite(screen,fundos[i],i*72+(i*3)+DIS_CENTRA,200);
   				draw_sprite(screen,selecao[1],pos_fundo[pos_3].x,pos_fundo[pos_3].y);
   				print_personagens_selecionados();
		   		fflush(stdin);
				switch(movimenta_1()){
					case PRESS_D:
						if(pos_3<NUM_FUNDOS-1)pos_3++;
						break;
					case PRESS_A:
						if(pos_3>0)pos_3--;
						break;
				}
				switch(movimenta_2()){
					case PRESS_D:
						if(pos_3<NUM_FUNDOS-1)pos_3++;
						break;
					case PRESS_A:
						if(pos_3>0)pos_3--;
						break;
				}
				if(key[KEY_ENTER]||alea){
					select_mapa(pos_3);
					delay(1);
					aux=multiplayer_a_computer();
					if(aux>=0)ganha[aux]++;
					alea=false;
					ale[0]=ale[1]=ale[2]=0;
					if(trapaca){
						trapaca=false;
						stop_sample(trapa);
						tocando_1=false;
					}
					//stop_sample( musica [tocar]);
					//tocando_1=0;
					break;
				}
   				delay(1.0/(QUADROS_POR_SEGUNDO-47));
   				switch(pos_3){
   					case 0:
   						fundo_menu=load_bitmap("program/img/menu/fundo_game.pcx",NULL);
   						break;
   					case 1:
   						fundo_menu=load_bitmap("program/img/menu/fundo_game_01.pcx",NULL);
   						break;
   					case 2:
   						fundo_menu=load_bitmap("program/img/menu/fundo_game_02.pcx",NULL);
   						break;
   					case 3:
   						fundo_menu=load_bitmap("program/img/menu/fundo_game_03.pcx",NULL);
   						break;
   					case 4:
   						fundo_menu=load_bitmap("program/img/menu/fundo_game_04.pcx",NULL);
   						break;
   					case 5:
   						fundo_menu=load_bitmap("program/img/menu/fundo_game_05.pcx",NULL);
   						break;
   					case 6:
   						fundo_menu=load_bitmap("program/img/menu/fundo_game_06.pcx",NULL);
   						break;
   				}
   			}
   			delay(0.5);
		}

		delay(1.0/(QUADROS_POR_SEGUNDO-47));
		contador;
		if(contador==tim){
			fundo_menu=load_bitmap("program/img/menu/fundo_01.pcx",NULL);
		}else{
			if(contador==tim*2){
				fundo_menu=load_bitmap("program/img/menu/fundo_02.pcx",NULL);
			}else{
				if(contador==tim*3){
					fundo_menu=load_bitmap("program/img/menu/fundo_03.pcx",NULL);
				}else{
					if(contador==tim*4){
						fundo_menu=load_bitmap("program/img/menu/fundo.pcx",NULL);
						contador=0;
					}
				}
			}
		}
	}
	stop_sample( musica[0] );
	delete  *gamer;
	delete *gamer_life;
	delete tmp_player_0;
	delete tmp_player_1;
	delete *itens;
	delete *fundo;
	delete *bau;
	delete *objetos_screen;
	delete morte;
	delete deft;
	delete fundo_menu;
	delete *faces;
	delete quadro;
	delete *fundos;
	delete musica[0];
   	finaliza_allegro();
	return -1;//para sair do jogo
}
void Interface::select_mapa(int a){
	if(alea){
		a=rand()%7;
	}
	switch(a){
		case  fundo_:
			fundo[0]=load_bitmap("program/img/background/fundo.pcx",NULL);
			break;
		case fundo_kame:
			fundo[0]=load_bitmap("program/img/background/fundo_kame.pcx",NULL);
			break;
		case fundo_tatame:
			fundo[0]=load_bitmap("program/img/background/fundo_tatame.pcx",NULL);
			break;
		case fundo_terra:
			fundo[0]=load_bitmap("program/img/background/fundo_terra.pcx",NULL);
			break;
		case fundo_portal:
			fundo[0]=load_bitmap("program/img/background/fundo_portal.pcx",NULL);
			if(fundo[0]==NULL)printf("deu merda1\n");
			break;
		case fundo_armory:
			fundo[0]=load_bitmap("program/img/background/fundo_armory.pcx",NULL);
			if(fundo[0]==NULL)printf("deu merda2\n");
			break;
		case fundo_xlarge:
			fundo[0]=load_bitmap("program/img/background/fundo_xlarge.pcx",NULL);
			if(fundo[0]==NULL)printf("deu merda3\n");
			break;
		default:
			fundo[0]=load_bitmap("program/img/background/fundo_tatame.pcx",NULL);
			break;
	}
}
void Interface::load_personagens(){
	faces[NUM_16]=load_bitmap("program/img/menu/16.pcx",NULL);
	faces[NUM_18]=load_bitmap("program/img/menu/18.pcx",NULL);
	faces[bils]=load_bitmap("program/img/menu/bils.pcx",NULL);
	faces[cell]=load_bitmap("program/img/menu/cell.pcx",NULL);
	faces[freza]=load_bitmap("program/img/menu/freza.pcx",NULL);
	faces[gohan]=load_bitmap("program/img/menu/gohan.pcx",NULL);
	faces[goku]=load_bitmap("program/img/menu/goku.pcx",NULL);
	faces[goku3]=load_bitmap("program/img/menu/goku3.pcx",NULL);
	faces[mestre_kame]=load_bitmap("program/img/menu/kame.pcx",NULL);
	faces[kuririm]=load_bitmap("program/img/menu/kuririm.pcx",NULL);
	faces[piculo]=load_bitmap("program/img/menu/piculo.pcx",NULL);
	faces[mr_satan]=load_bitmap("program/img/menu/satan.pcx",NULL);
	faces[supremo_senhor_kaio]=load_bitmap("program/img/menu/supremo.pcx",NULL);
	faces[vegeta]=load_bitmap("program/img/menu/vegeta.pcx",NULL);


	fundos[fundo_]=load_bitmap("program/img/menu/p_fundo.pcx",NULL);
	fundos[fundo_kame]=load_bitmap("program/img/menu/p_fundo_kame.pcx",NULL);
	fundos[fundo_tatame]=load_bitmap("program/img/menu/p_fundo_tatame.pcx",NULL);
	fundos[fundo_terra]=load_bitmap("program/img/menu/p_fundo_terra.pcx",NULL);
	fundos[fundo_portal]=load_bitmap("program/img/menu/p_fundo_portal.pcx",NULL);
	fundos[fundo_armory]=load_bitmap("program/img/menu/p_fundo_armory.pcx",NULL);
	fundos[fundo_xlarge]=load_bitmap("program/img/menu/p_fundo_xlarge.pcx",NULL);



	selecao[0]=load_bitmap("program/img/menu/player_1_selecao.pcx",NULL);
	selecao[1]=load_bitmap("program/img/menu/player_2_selecao.pcx",NULL);

	fundo_menu=load_bitmap("program/img/menu/fundo.pcx",NULL);

	quadro=load_bitmap("program/img/menu/quadro.pcx",NULL);
	for(i=0;i<NUM_PERSONAGENS/2;i++){
			pos_faces[i].x=i*72+(i*3)+DIS_CENTRA;
			pos_faces[i].y=10;
			//draw_sprite(screen,faces[i],i*72+(i*3),5);
		}
	for(j=0;i<NUM_PERSONAGENS;i++,j++){
		pos_faces[i].x=j*72+(j*3)+DIS_CENTRA;
		pos_faces[i].y=95;
		//draw_sprite(screen,faces[i],j*72+(j*3),90);
	}
	for(i=0;i<NUM_FUNDOS;i++){
		pos_fundo[i].x=i*72+(i*3)+DIS_CENTRA;
		pos_fundo[i].y=200;
	}
}
void Interface::select_personagem(int op,int game){
	if(game>1||game<0||op>NUM_PERSONAGENS||op<0)return;
	delete gamer[game];
	if(alea){
		op=rand()%13;
	}
	switch(op){
		case NUM_16:
			gamer[game]=new jogador("program/img/16",false,1);
			gamer_life[game]=new Androide();
			if(game){
				al_j1=250;
			}else{
				al_j0=250;
			}
			break;
		case NUM_18:
			gamer[game]=new jogador("program/img/18",false,1);
			gamer_life[game]=new Androide();
			if(game){
				al_j1=290;
			}else{
				al_j0=290;
			}
			break;
		case bils:
			gamer[game]=new jogador("program/img/bils",false,1);
			gamer_life[game]=new Deus_da_distruicao();
			if(game){
				al_j1=240;
			}else{
				al_j0=240;
			}
			break;
		case cell:
			gamer[game]=new jogador("program/img/cell",false,1);
			gamer_life[game]=new Androide();
			if(game){
				al_j1=250;
			}else{
				al_j0=250;
			}
			break;
		case freza:
			gamer[game]=new jogador("program/img/freza",false,1);
			gamer_life[game]=new Freza();
			if(game){
				al_j1=290;
			}else{
				al_j0=290;
			}
			break;
		case gohan:
			gamer[game]=new jogador("program/img/gohan",false,1);
			gamer_life[game]=new Super_Sayadim_2();
			if(game){
				al_j1=300;
			}else{
				al_j0=300;
			}
			break;
		case goku:
			gamer[game]=new jogador("program/img/goku",false,1);
			gamer_life[game]=new Super_Sayadim();
			if(game){
				al_j1=270;
			}else{
				al_j0=270;
			}
			break;
		case goku3:
			gamer[game]=new jogador("program/img/goku3",false,1);
			gamer_life[game]=new Super_Sayadim_3();
			if(game){
				al_j1=270;
			}else{
				al_j0=270;
			}
			break;
		case kuririm:
			gamer[game]=new jogador("program/img/kuririm",false,1);
			gamer_life[game]=new Humano();
			if(game){
				al_j1=300;
			}else{
				al_j0=300;
			}
			break;
		case mestre_kame:
			gamer[game]=new jogador("program/img/mestre_kame",false,1);
			gamer_life[game]=new Humano();
			if(game){
				al_j1=290;
			}else{
				al_j0=290;
			}
			break;
		case mr_satan:
			gamer[game]=new jogador("program/img/mr_satan",false,1);
			gamer_life[game]=new Humano();
			if(game){
				al_j1=280;
			}else{
				al_j0=280;
			}
			break;
		case piculo:
			gamer[game]=new jogador("program/img/picolo",false,1);
			gamer_life[game]=new Picculo();
			if(game){
				al_j1=270;
			}else{
				al_j0=270;
			}
			break;
		case supremo_senhor_kaio:
			gamer[game]=new jogador("program/img/supremo_senhor_kaio",false,1);
			gamer_life[game]=new Seres_Supremos();
			if(game){
				al_j1=280;
			}else{
				al_j0=280;
			}
			break;
		case vegeta:
			gamer[game]=new jogador("program/img/vegeta",false,1);
			gamer_life[game]=new Super_Sayadim_2();
			if(game){
				al_j1=280;
			}else{
				al_j0=280;
			}
			break;
	}
	if(game==1){
		gamer[1]->troca_orientacao();
	}
   	tempo_0=0;
   	tempo_1=0;
}
void Interface::print_personagens_selecionados(){
	gamer[0]->get_orientacao_sprite()?draw_sprite_h_flip(screen,tmp_player_0,gamer[0]->get_x(),gamer[0]->get_y()):draw_sprite(screen,tmp_player_0,gamer[0]->get_x(),gamer[0]->get_y());
    gamer[1]->get_orientacao_sprite()?draw_sprite_h_flip(screen,tmp_player_1,gamer[1]->get_x(),gamer[1]->get_y()):draw_sprite(screen,tmp_player_1,gamer[1]->get_x(),gamer[1]->get_y());
	
	tempo_0++;
	if(tempo_0==DELAY_LEITURA-3)tempo_0=0;
	if(!tempo_0)movi_0[PAR]++;
	if(movi_0[PAR] == gamer[0]-> num_sprites(PAR))movi_0[PAR]=0;
	tmp_player_0=gamer[0]-> acesso_stripe(PAR,movi_0[PAR]);

	tempo_1++;
	if(tempo_1==DELAY_LEITURA-2)tempo_1=0;
	if(!tempo_1)movi_1[PAR]++;
	if(movi_1[PAR] == gamer[1]-> num_sprites(PAR))movi_1[PAR]=0;
	tmp_player_1=gamer[1]-> acesso_stripe(PAR,movi_1[PAR]);
}