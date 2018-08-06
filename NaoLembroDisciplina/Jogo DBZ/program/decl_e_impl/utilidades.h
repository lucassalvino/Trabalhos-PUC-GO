#include <string>
using namespace std;
Joystick joystick("/dev/input/js1");
Joystick joystick2("/dev/input/js2");
JoystickEvent event;
//pode ser uti
void delay (float delay1) {
   if (delay1<0)return;
   float inst1=0, inst2=0;
   inst1 = (float)clock()/(float)CLOCKS_PER_SEC;
   while (inst2-inst1<delay1)inst2=(float)clock()/(float)CLOCKS_PER_SEC;
   return;
}

void string_to_char(string ori,char des[]){
	*des=0;int i;
	for(i=0;ori[i]!='\0';i++){
		des[i]=ori[i];
	}
	des[i]='\0';
	return;
}

void inicializa_allegro(int x,int y,string title){
	allegro_init();//inicializa o allegro
   	install_keyboard();//configura teclado 
   	install_mouse();//inicialisa mause
   	set_color_depth(32);//seta modelo de cor 32 bits
   	install_sound( DIGI_AUTODETECT, MIDI_AUTODETECT, "" );
    set_volume( 255, 255 );
   	// install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL);
   	set_gfx_mode(GFX_AUTODETECT_WINDOWED, x, y, 0, 0);
   	char title_char[title.size()+1];
   	string_to_char(title,title_char);
	set_window_title(title_char);
	return;
}
void reiniciaza_allegro(string title,int x,int y){
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, x, y, 0, 0);
	char title_char[title.size()+1];
	string_to_char(title,title_char);
	set_window_title(title_char);
}
void finaliza_allegro(){
	remove_keyboard();
	remove_mouse();
	allegro_exit();
}


void printf_tela(BITMAP* p1, int xp1, int yp1, BITMAP* p2, int xp2, int yp2, BITMAP* fundo){
	draw_sprite(screen,p1,xp1,yp1);
	draw_sprite(screen,p2,xp2,yp2);
	draw_sprite(screen,fundo,0,0);
}
void printf_tela(BITMAP* p1, int xp1, int yp1, BITMAP* p2, int xp2, int yp2){
	//clear(screen);
	draw_sprite(screen,p1,xp1,yp1);
	draw_sprite(screen,p2,xp2,yp2);
}
#define NUM_MOVI 9
#define and_D 0
#define and_A 1
#define and_W 2
#define and_S 3
#define ata_PR 4
#define ara_SE 5
#define def_X 6
#define selec 7
#define start_esc 8


int joy_jogador[2][NUM_MOVI];


void null(int jog,int ex){
	if(ex<0){
		for(int cont=0;cont<NUM_MOVI;cont++)
			joy_jogador[jog][cont]=0;
	}
	else{
		for(int cont=0;cont<NUM_MOVI;cont++)
			if(cont!=ex)joy_jogador[jog][cont]=0;
	}
}

int andar_a=0,andar_d=0,joy_pr=0,joy_se=0,fun=0,and_s=0,and_w=0,def=0;
int andar_a_1=0,andar_d_1=0,joy_pr_1=0,joy_se_1=0,fun_1=0,and_s_1=0,and_w_1=0,def_1=0;
bool jog1=false;
//andar_a=andar_d=joy_pr=fun=and_s=joy_se=and_w=def=0;
int joy_teste(int jog){
    if (joystick.sample(&event))
    {
      if (event.isButton())
      {
	  	switch(event.number){
	  		case 7://fun
	  			if(fun==0){fun=1;jog1=true;}
	  			else fun=0;
	  			joy_pr=andar_a=andar_d=and_w=and_s=def=0;
	  			break;
	  		case 10:
	  			if(joy_pr==0){joy_pr=1;fun=andar_a=andar_d=def=0;jog1=true;break;}
	  			joy_pr=0;
	  			fun=andar_a=andar_d=and_w=and_s=def=0;
	  			break;
	  		case 2://defende
	  			if(def==0){def=1;jog1=true;}
	  			else def=0;
	  			andar_a=andar_d=joy_pr=fun=and_s=and_w=0;
	  			break;
	  		case 1://atak se
	  			if(joy_pr==0){joy_pr=1;fun=andar_a=andar_d=def=0;jog1=true;break;}
	  			joy_pr=0;
	  			fun=andar_a=andar_d=and_w=and_s=def=0;
	  			break;
	  	}
      }
      else if (event.isAxis())
      {
      	joy_pr=0;
      	if(event.number==0){
      		if(event.value<0){
      			andar_a++;jog1=true;
      			joy_pr=fun=andar_d=and_w=and_s=def=0;
      		}else{
      			if(event.value>0){
      				andar_d++;jog1=true;
      				joy_pr=fun=andar_a=and_w=and_s=def=0;
      			}
      			if(event.value==0){
      				andar_a=andar_d=0;
      			}
      		}
      	}else{
      		if(event.value<0){
      			and_w++;
      			andar_a=andar_d=joy_pr=fun=and_s=def=0;
      		}else{
      			if(event.value>0){
      				and_s++;
      				andar_a=andar_d=joy_pr=fun=and_w=def=0;
      			}
      			if(event.value==0){
      				and_s=and_w=0;
      			}
      		}
      	}
        //printf("Axis_1 → %d → %d\n", event.number, event.value);
      }

    }else{
    	//if(jog1)andar_a=andar_d=joy_pr=fun=and_s=joy_se=and_w=def=0;
    }
    return -9;
}
int movimenta_player_1(int &x,int &y){
	joy_teste(0);
	if(key[KEY_D]||andar_d){x+=INCREMENTO;return PRESS_D;}
	if(key[KEY_A]||andar_a){x-=INCREMENTO;return PRESS_A;}
	if(key[KEY_W]||and_w){y-=INCREMENTO;return PRESS_W;}
	if(key[KEY_S]||and_s){y+=INCREMENTO;return PRESS_S;}
	if(key[KEY_X]||def)return PRESS_X;//defesa
	if(key[KEY_C]||joy_pr)return PRESS_C;//um ataque
	if(key[KEY_E]||joy_se)return PRESS_E;//o outro ataque
	if(key[KEY_F]||fun)return PRESS_F;//abri bau
	if(key[KEY_ESC])return PRESS_ESC;
	//delay(1.0/DELAY_LEITURA);
	return PRESS_VOID;
}
int joy_teste(){
    if (joystick2.sample(&event))
    {
      if (event.isButton())
      {
	  	switch(event.number){
	  		case 7://atake primario
	  			if(fun_1==0)fun_1=1;
	  			else fun_1=0;
	  			joy_pr_1=andar_a_1=andar_d_1=and_w_1=and_s_1=def_1=0;
	  			break;
	  		case 10://atake teste
	  			if(joy_pr_1==0){joy_pr_1=1;fun_1=andar_a_1=andar_d_1=def_1=0;break;}
	  			joy_pr_1=0;
	  			fun_1=andar_a_1=andar_d_1=and_w_1=and_s_1=def_1=0;
	  			break;
	  		case 2://defende
	  			if(def_1==0)def_1=1;
	  			else def_1=0;
	  			andar_a_1=andar_d_1=joy_pr_1=fun_1=and_s_1=and_w_1=0;
	  			break;
	  		case 1:
	  			if(joy_pr_1==0){joy_pr_1=1;fun_1=andar_a_1=andar_d_1=def_1=0;break;}
	  			joy_pr_1=0;
	  			fun_1=andar_a_1=andar_d_1=and_w_1=and_s_1=def_1=0;
	  			break;
	  	}
      }
      else if (event.isAxis())
      {
      	joy_pr_1=0;
      	if(event.number==0){
      		if(event.value<0){
      			andar_a_1++;
      			joy_pr_1=fun_1=andar_d_1=and_w_1=and_s_1=def_1=0;
      		}else{
      			if(event.value>0){
      				andar_d_1++;
      				joy_pr_1=fun_1=andar_a_1=and_w_1=and_s_1=def_1=0;
      			}
      			if(event.value==0){
      				andar_a_1=andar_d_1=0;
      			}
      		}
      	}else{
      		if(event.value<0){
      			and_w_1++;
      			andar_a_1=andar_d_1=joy_pr_1=fun_1=and_s_1=def_1=0;
      		}else{
      			if(event.value>0){
      				and_s_1++;
      				andar_a_1=andar_d_1=joy_pr_1=fun_1=and_w_1=def_1=0;
      			}
      			if(event.value==0){
      				and_s_1=and_w_1=0;
      			}
      		}
      	}
        //printf("Axis_1 → %d → %d\n", event.number, event.value);
      }

    }else{
    	//andar_a_1=andar_d_1=joy_pr_1=fun_1=and_s_1=joy_se_1=and_w_1=def_1=0;
    }
    return -9;
}
int movimenta_player_2(int &x1,int &y1){
	joy_teste();
	if(key[KEY_6_PAD]||key[KEY_6]||key[KEY_RIGHT]||andar_d_1){x1+=INCREMENTO;return PRESS_D;}
	if(key[KEY_4_PAD]||key[KEY_4]||key[KEY_LEFT]||andar_a_1){x1-=INCREMENTO;return PRESS_A;}
	if(key[KEY_8_PAD]||key[KEY_8]||key[KEY_UP]||and_w_1){y1-=INCREMENTO;return PRESS_W;}
	if(key[KEY_5_PAD]||key[KEY_5]||key[KEY_DOWN]||and_s_1){y1+=INCREMENTO;return PRESS_S;}
	if(key[KEY_3_PAD]||key[KEY_3]||def_1)return PRESS_L;//DEFENDE
	if(key[KEY_7_PAD]||key[KEY_7]||joy_pr_1)return CLICKD_LEFT;
	if(key[KEY_9_PAD]||key[KEY_9]||joy_se_1){return CLICKD_RIGHT;}//corrigir
	if(key[KEY_1_PAD]||key[KEY_1]||fun_1)return PRESS_F;//abri bau
	if(key[KEY_ESC])return PRESS_ESC;
	return PRESS_VOID;
}
int movimenta_1(){
	if(key[KEY_D]){return PRESS_D;}
	if(key[KEY_A]){return PRESS_A;}
	if(key[KEY_S]){return PRESS_S;}
	if(key[KEY_W]){return PRESS_W;}
	return PRESS_VOID;
}
int movimenta_2(){
	if(key[KEY_RIGHT]){return PRESS_D;}
	if(key[KEY_LEFT]){return PRESS_A;}
	if(key[KEY_DOWN]){return PRESS_S;}
	if(key[KEY_UP]){return PRESS_W;}
	return PRESS_VOID;	
}

bool valida_mapa(int lx,int ly, int x,int y){
	if(x<0||y<54)return false;
	if(x>lx/2+350||y>ly/2+100)return false;
	return true;
}
void troca (int &a, int &b){
	int c;
	c=a;
	a=b;
	b=c;
	return;
}
/*
Considerando X1 e Y1 coordenadas do 1º elemento, X2 e Y2 do 2º elemento, H1 e W1 altura e largura do 1º, e H2 e W2 altura e largura do 2º.
Não haverá colisão nos seguintes casos:
X1 > X2 + W2
Y1 > Y2 + H2
X1 + W1 < X2
Y1 + H1 < Y2
*/
bool colisao(int x,int y,int x1,int y1){
	if(x>x1+LARGURAM)return false;
	if(y>y1+ALTURAM)return false;
	if(x+LARGURAM<x1)return false;
	if(y+ALTURAM<y1)return false;
	return true;
}

void load_items_bau(){
	image_items[NADA]=load_bitmap("program/img/itens/void.pcx",NULL);
	image_items[CASCO_TARTARUGA]=load_bitmap("program/img/itens/casco_tartaruga.pcx",NULL);
	image_items[ESPADA]=load_bitmap("program/img/itens/espada_z.pcx",NULL);
	image_items[LUA_CHEIA]=load_bitmap("program/img/itens/lua_cheia.pcx",NULL);
	image_items[MESTRE_KAME]=load_bitmap("program/img/itens/mestre_kame.pcx",NULL);
	image_items[NUVEM_VOADORA]=load_bitmap("program/img/itens/nuvem_voadora.pcx",NULL);
	image_items[PEIXE]=load_bitmap("program/img/itens/peixe.pcx",NULL);
	image_items[SEMENTE_DOS_DEUSES]=load_bitmap("program/img/itens/semente_dos_deuses.pcx",NULL);
	image_items[SENHOR_KAIO]=load_bitmap("program/img/itens/senhor_kaio.pcx",NULL);
	image_items[ZENI]=load_bitmap("program/img/itens/zeni.pcx",NULL);
	image_items[TITI]=load_bitmap("program/img/itens/titi.pcx",NULL);
	image_items[BULMA]=load_bitmap("program/img/itens/bulma.pcx",NULL);
	image_items[LANCHI]=load_bitmap("program/img/itens/lanchi.pcx",NULL);
	image_items[BABIDI]=load_bitmap("program/img/itens/babidi_r_energia.pcx",NULL);
	image_items[CELL]=load_bitmap("program/img/itens/babidi_r_energia.pcx",NULL);
}
void null_vector(int *vet,int n,int ex){
	if(ex<0){
		for(int cont=0;cont<n;cont++)
			vet[cont]=0;
	}
	else{
		for(int cont=0;cont<n;cont++)
			if(cont!=ex)vet[cont]=0;
	}
	return;
}