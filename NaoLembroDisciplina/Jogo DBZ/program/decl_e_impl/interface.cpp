#include "interface.h"
#include "menu.h"
void Interface::start()
{
    srand(time(NULL));
    inicializa_allegro(X_LINHA*2-10,Y_COLUNA,TITLE);
    menu();
}
int lua[3]= {0},a,tmp=0;
int a_0=0,b_0=0,a_1=0,b_1=0;
bool valida_chet(int num)
{
    for(int i=0; i<3; i++)
        if(lua[i]!=num)return false;
    return true;
}
char save[]="capturas/screen_00.pcx";
int Interface::multiplayer_a_computer()
{
    print_status_jogadores();
    algem_morreu=false;
    while(!key[KEY_ESC])
    {
        draw_sprite(screen,fundo[0],0,56);
        if(mostrar_bau[2]!=500&&mostrar_bau[0]==1000)
        {
            draw_sprite(screen,bau[0],po_bau,300);
        }
        if(algem_morreu)
        {
            draw_sprite(screen,objetos_screen[FATALITY],200,60);
        }
        gamer[0]->get_orientacao_sprite()?draw_sprite_h_flip(screen,tmp_player_0,gamer[0]->get_x(),gamer[0]->get_y()):draw_sprite(screen,tmp_player_0,gamer[0]->get_x(),gamer[0]->get_y());
        gamer[1]->get_orientacao_sprite()?draw_sprite_h_flip(screen,tmp_player_1,gamer[1]->get_x(),gamer[1]->get_y()):draw_sprite(screen,tmp_player_1,gamer[1]->get_x(),gamer[1]->get_y());
        x=gamer[0]->get_x();
        y=gamer[0]->get_y();
        x1=gamer[1]->get_x();
        y1=gamer[1]->get_y();
        trava_player_2=false;
        tmp++;
        if(key[KEY_H])
        {
            save_bitmap(save, screen, NULL);
            delay(0.5);
            save[17]++;
            if(save[17]=='9')
            {
                save[17]='0';
                save[16]++;
            }
        }
        if(key[KEY_L])lua[0]=1;
        if(key[KEY_U])lua[1]=1;
        if(key[KEY_A])lua[2]=1;
        if(key[KEY_V])lua[0]=2;
        if(key[KEY_I])lua[1]=2;
        if(key[KEY_D])lua[2]=2;
        if(valida_chet(1)) //o 0 ganhou
        {
            gamer_life[0]->novo_item(true);
            print_status_jogadores();
            lua[0]=lua[1]=lua[2]=0;
        }
        else
        {
            if(valida_chet(2)) //o 1 ganhou
            {
                gamer_life[1]->novo_item(true);
                print_status_jogadores();
                lua[0]=lua[1]=lua[2]=0;
            }
        }
        if(tmp==100)lua[0]=lua[1]=lua[2]=0;
        fflush(stdin);
        if(gamer_life[0]->get_vida()>0)
        {
            switch(movimenta_player_1(x,y))
            {
            case PRESS_VOID:
            {
                null_vector(movi_0,NUM_ANIMA,PAR);
                tempo_0++;
                travado_0=golpe_pr_0=false;
                if(tempo_0==DELAY_LEITURA+15)tempo_0=0;
                if(!tempo_0)movi_0[PAR]++;
                if(movi_0[PAR] == gamer[0]-> num_sprites(PAR))movi_0[PAR]=0;
                tmp_player_0=gamer[0]-> acesso_stripe(PAR,movi_0[PAR]);
                if(y<al_j0)y++;
                if(y>al_j0)y=al_j0;
                gamer_life[0]->set_defende(false);
                break;
            }
            case PRESS_D:
            {
                event_prees_tecla(0,AND,true, DELAY_LEITURA/2);
                if(gamer[0]->get_orientacao_sprite()!=backp_0)gamer[0]->troca_orientacao();
                break;
            }
            case PRESS_A:
            {
                event_prees_tecla(0,AND,true,DELAY_LEITURA/2);
                if(gamer[0]->get_orientacao_sprite()==backp_0)gamer[0]->troca_orientacao();
                break;
            }
            case PRESS_W:
            {
                event_prees_tecla(0,PUL,true,DELAY_LEITURA);
                break;
            }
            case PRESS_X: //defender
            {
                event_prees_tecla(0,DEF,true,DELAY_LEITURA);
                gamer_life[0]->set_defende(true);
                break;
            }
            case PRESS_C: //ATAKE PRIMARIO
            {
                if(gamer_life[0]->get_energia()==0)
                {
                    break;
                }
                else golpe_pr_0=true;
                event_prees_tecla(0,ATAC_PR,false,DELAY_LEITURA/(VELOCIDADE_ATACK)+gamer_life[0]->get_destreza());
                if(da_para_atacar() && dividindo_golpes(movi_0[ATAC_PR],gamer[0]->num_sprites(ATAC_PR)-1) && estao_de_frente())
                {
                    if(gamer_life[1]->levar_dano(gamer_life[0]->realizar_ataque_primario()))
                    {
                        //draw_sprite(screen,combo,200,60);
                        gamer_life[0]->set_energia(gamer_life[0]->get_energia()+10);
                    }
                    trava_player_2=true;
                    tmp_player_1=gamer[1]->acesso_stripe(CAI,0);
                }
                else
                {
                    if((movi_0[ATAC_PR] == gamer[0]->num_sprites(ATAC_PR)-1))
                    {
                        gamer_life[0]->realizar_ataque_primario();
                        golpe_pr_0=false;
                    }
                }
                //if(movi_0[ATAC_PR]==gamer[0]->num_sprites(ATAC_PR)-1)joy_pr=0;
                print_status_jogadores();
                break;
            }
            case PRESS_E: //atac secundario
            {
                int a=80,b=8,c=5;
                event_prees_tecla(0,ATAC_SE,true,DELAY_LEITURA-15);
                if((movi_0[ATAC_SE] == gamer[0]->num_sprites(ATAC_SE)-1) && gamer_life[0]->get_energia()>=10)
                {
                    if(gamer[0]->get_orientacao_sprite()==backp_0)
                    {
                        draw_sprite(screen,gamer[0]->acesso_sprite_power(0),x+a,y+b+6);
                    }
                    else
                    {
                        draw_sprite_h_flip(screen,gamer[0]->acesso_sprite_power(0),x-a+20,y-b+30);
                    }
                    for(c=0; c<25; c++) //imprime rastro
                    {
                        if(gamer[0]->get_orientacao_sprite()==backp_0)
                        {
                            draw_sprite(screen,gamer[0]->acesso_sprite_power(1),x+a+(c*32)+36,y+b+11);
                        }
                        else
                        {
                            draw_sprite_h_flip(screen,gamer[0]->acesso_sprite_power(1),x-a-(c*32)-10,y-b+35);
                        }
                        bool teste;
                        if(gamer[0]->get_orientacao_sprite()==backp_0)teste=colisao(x+a+(c*32)+36,y+b+5,x1,y1);
                        else teste=colisao(x-a-(c*32)-26,y-b+10,x1,y1);
                        if(teste) //colidiuo com outro adversario
                        {
                            if(gamer[0]->get_orientacao_sprite()==backp_0) //orientação normal
                            {
                                draw_sprite(screen,gamer[0]->acesso_sprite_power(2),x+a+(c*32)+36+5,y+b+6);
                            }
                            else
                            {
                                draw_sprite_h_flip(screen,gamer[0]->acesso_sprite_power(2),x-a-(c*32)-16,y-b+30);
                            }
                            break;
                        }
                        else
                        {
                            gamer_life[0]->realizar_ataque_secundario();
                            delay(0.003);
                        }
                    }
                    if(gamer[0]->get_orientacao_sprite()==backp_0?colisao(x+a+(c*32)+36,y+b+5,x1,y1):colisao(x-a-(c*32)-36,y-b-5,x1,y1))
                    {
                        //draw_sprite(screen,gamer[0]->acesso_sprite_power(2),x+a+(c*32)+36+5,y+b);
                        gamer_life[1]->levar_dano(gamer_life[0]->realizar_ataque_secundario());
                        print_status_jogadores();
                        delay(0.07);
                    }
                }
                break;
            }
            case PRESS_F:
            {
                if(colisao(x,y,po_bau,300)&&mostrar_bau[1])
                {
                    gamer_life[0]->novo_item(false);
                    print_status_jogadores();
                    mostrar_bau[0]=mostrar_bau[1]=mostrar_bau[2]=0;
                }
                break;
            }
            case PRESS_ESC:
            {
                break;
            }
            }
        }
        else  //gamer 0 morreu
        {
            event_prees_tecla(0,CAI,true,DELAY_LEITURA*2-10);
            y+=1;
            algem_morreu=true;
            if(y>=al_j0)
            {
                draw_sprite(screen,objetos_screen[FATALITY],200,60);
                delay(3);
                return 1;//o jogadoer 1 ganhou
            }
        }
        if (valida_mapa(X_LINHA*2-10,Y_COLUNA,x,y)&&!colisao(x,y,x1,y1))
            gamer[0]->set_x_y(x,y);
        fflush(stdin);
        if(gamer_life[1]->get_vida()>0)
        {
            if(!trava_player_2)
                switch(movimenta_player_2(x1,y1))
                {
                case PRESS_VOID: //CASO O JOGADOR NÃO TECLE EM NADA
                {
                    null_vector(movi_1,NUM_ANIMA,PAR);
                    tempo_1++;
                    travado_1=golpe_pr_1=false;
                    if(tempo_1==DELAY_LEITURA+15)tempo_1=0;
                    if(!tempo_1)movi_1[PAR]++;
                    if(movi_1[PAR] == gamer[1]-> num_sprites(PAR))movi_1[PAR]=0;
                    tmp_player_1=gamer[1]-> acesso_stripe(PAR,movi_1[PAR]);
                    if(y1<al_j1)y1+=1;
                    if(y1>al_j1)y1=al_j1;
                    gamer_life[1]->set_defende(false);
                    break;
                }
                case PRESS_D:
                {
                    event_prees_tecla(1,AND,true,DELAY_LEITURA);
                    if(gamer[1]->get_orientacao_sprite()==backp_1)gamer[1]->troca_orientacao();
                    break;
                }
                case PRESS_A:
                {
                    event_prees_tecla(1,AND,true,DELAY_LEITURA);
                    if(gamer[1]->get_orientacao_sprite()!=backp_1)gamer[1]->troca_orientacao();
                    break;
                }
                case PRESS_W:
                {
                    event_prees_tecla(1,PUL,true,DELAY_LEITURA);
                    break;
                }
                case PRESS_L:
                {
                    event_prees_tecla(1,DEF,true,DELAY_LEITURA);
                    gamer_life[1]->set_defende(true);
                    print_status_jogadores();
                    break;
                }
                case CLICKD_LEFT: //atack primario
                {
                    if(gamer_life[1]->get_energia()==0||gamer_life[1]->get_vida()==0)break;
                    else golpe_pr_1=true;
                    if(gamer_life[1]->get_energia()==0||gamer_life[1]->get_vida()==0)break;
                    event_prees_tecla(1,ATAC_PR,false,DELAY_LEITURA/(VELOCIDADE_ATACK)+gamer_life[1]->get_destreza());
                    if(golpe_pr_1 && da_para_atacar() && dividindo_golpes(movi_1[ATAC_PR],gamer[1]->num_sprites(ATAC_PR)-1) && estao_de_frente())
                    {
                        if(gamer_life[0]->levar_dano(gamer_life[1]->realizar_ataque_primario()))
                        {
                            draw_sprite(screen,combo,260,60);
                            gamer_life[0]->set_energia(gamer_life[0]->get_energia()+10);
                        }
                        trava_player_2=true;
                        tmp_player_0=gamer[0]->acesso_stripe(CAI,0);
                    }
                    else
                    {
                        if((movi_1[ATAC_PR] == gamer[1]->num_sprites(ATAC_PR)-1))
                        {
                            gamer_life[1]->realizar_ataque_primario();
                            golpe_pr_1=false;
                        }
                    }
                    print_status_jogadores();
                    break;
                }
                case CLICKD_RIGHT: //atac secundario
                {
                    int a=80,b=8,c=5;
                    event_prees_tecla(1,ATAC_SE,true,DELAY_LEITURA-15);
                    if((movi_1[ATAC_SE] == gamer[1]->num_sprites(ATAC_SE)-1) && gamer_life[1]->get_energia()>=10)
                    {
                        if(gamer[1]->get_orientacao_sprite()==backp_1)
                        {
                            draw_sprite_h_flip(screen,gamer[1]->acesso_sprite_power(0),x1-a+20,y1-b+30);
                        }
                        else
                        {
                            draw_sprite(screen,gamer[1]->acesso_sprite_power(0),x1+a,y1+b+6);
                        }
                        for(c=0; c<25; c++) //imprime rastro
                        {
                            if(gamer[1]->get_orientacao_sprite()==backp_1)
                            {
                                draw_sprite_h_flip(screen,gamer[1]->acesso_sprite_power(1),x1-a-(c*32)-10,y1-b+35);
                            }
                            else
                            {
                                draw_sprite(screen,gamer[1]->acesso_sprite_power(1),x1+a+(c*32)+36,y1+b+11);
                            }
                            bool teste;
                            if(gamer[1]->get_orientacao_sprite()==backp_1)teste=colisao(x1-a-(c*32)-26,y1-b+10,x,y);
                            else teste=colisao(x1+a+(c*32)+36,y1+b+5,x,y);
                            if(teste) //colidiuo com outro adversario
                            {
                                if(gamer[1]->get_orientacao_sprite()==backp_1) //orientação normal
                                {
                                    draw_sprite_h_flip(screen,gamer[1]->acesso_sprite_power(2),x1-a-(c*32)-16,y1-b+30);
                                }
                                else
                                {
                                    draw_sprite(screen,gamer[1]->acesso_sprite_power(2),x1+a+(c*32)+36+5,y1+b+6);
                                }
                                break;
                            }
                            else
                            {
                                gamer_life[1]->realizar_ataque_secundario();
                                delay(0.003);
                            }
                        }
                        if(gamer[1]->get_orientacao_sprite()==backp_1?colisao(x1-a-(c*32)-36,y1-b-5,x,y):colisao(x1+a+(c*32)+36,y1+b+5,x,y))
                        {
                            //draw_sprite(screen,gamer[0]->acesso_sprite_power(2),x+a+(c*32)+36+5,y+b);
                            gamer_life[0]->levar_dano(gamer_life[1]->realizar_ataque_secundario());
                            print_status_jogadores();
                            delay(0.07);
                        }
                    }
                    break;
                    break;
                }
                case PRESS_F:
                {
                    if(colisao(x1,y1,po_bau,300)&&mostrar_bau[1])
                    {
                        gamer_life[1]->novo_item(false);
                        print_status_jogadores();
                        mostrar_bau[0]=mostrar_bau[1]=mostrar_bau[2]=0;
                    }
                    break;
                }
                case PRESS_ESC:
                {
                    break;
                }
                }
        }
        else
        {
            //gamer [1] morreu;
            event_prees_tecla(1,CAI,true,DELAY_LEITURA*2-10);
            y1+=1;
            if(y1>=al_j1)
            {
                draw_sprite(screen,objetos_screen[FATALITY],200,60);
                delay(3);
                return 0;//o jogadoer 0 ganhou
            }
            algem_morreu=true;
        }
        if(valida_mapa(X_LINHA*2-10,Y_COLUNA,x1,y1)&&!colisao(x,y,x1,y1))
            gamer[1]->set_x_y(x1,y1);

        if(++carrega_ki==50)
        {
            if(gamer_life[0]->get_vida()>0)gamer_life[0]->set_energia((gamer_life[0]->get_energia())+1);
            if(gamer_life[1]->get_vida()>0)gamer_life[1]->set_energia((gamer_life[1]->get_energia())+1);
            print_status_jogadores();
            carrega_ki=0;
        }

        if(mostrar_bau[0]!=1000)mostrar_bau[0]++;
        if(mostrar_bau[0]==1000)
        {
            mostrar_bau[1]=1;
            if(mostrar_bau[2]==0)po_bau=rand()%750;
            mostrar_bau[2]++;
            if(mostrar_bau[2]==500)
            {
                mostrar_bau[0]=mostrar_bau[1]=mostrar_bau[2]=0;
                po_bau=0;
            }
        }
        delay(1.0/QUADROS_POR_SEGUNDO);
    }
    //volta para o  menu
    return -5;
}



//Interface::event_prees_tecla(int *vet,bool &trava,bool backp,int &tempo,jogador *dado,int movi,BITMAP* print,int jog)
void Interface::event_prees_tecla(int jog,int movimento,bool trava,int tempo)
{
    if(jog==0) //jogador == 0
    {
        null_vector(movi_0,NUM_ANIMA,movimento);
        tempo_0++;
        if(tempo_0>=tempo)tempo_0=0;
        if(!tempo_0&&!travado_0)movi_0[movimento]++;
        if(movi_0[movimento] == gamer[0]->num_sprites(movimento)&&trava)
        {
            movi_0[movimento]--;
            travado_0=true;
        }
        if(movi_0[movimento] == gamer[0]->num_sprites(movimento)&&!trava)
        {
            movi_0[movimento]=0;
        }
        tmp_player_0=gamer[0]->acesso_stripe(movimento,movi_0[movimento]);
    }
    else
    {
        null_vector(movi_1,NUM_ANIMA,movimento);
        tempo_1++;
        if(tempo_1>=tempo)tempo_1=0;
        if(!tempo_1&&!travado_1)movi_1[movimento]++;
        if(movi_1[movimento] == gamer[1]->num_sprites(movimento)&&trava)
        {
            movi_1[movimento]--;
            travado_1=true;
        }
        if(movi_1[movimento] == gamer[1]->num_sprites(movimento)&&!trava)
        {
            movi_1[movimento]=0;
        }
        tmp_player_1=gamer[1]->acesso_stripe(movimento,movi_1[movimento]);
    }
}
void Interface::print_status_jogadores()
{
    draw_sprite(screen,fundo[1],0,0);
    draw_sprite(screen,gamer[0]->acesso_face(),0,0);
    if(gamer_life[0]->get_vida()<=20)draw_sprite_h_flip(screen,morte,106,30);
    if(gamer_life[0]->get_energia()<=30)draw_sprite(screen,deft,0,0);
    draw_sprite_h_flip(screen,gamer[1]->acesso_face(),717,0);
    if(gamer_life[1]->get_vida()<=20)draw_sprite(screen,morte,650,30);
    if(gamer_life[1]->get_energia()<=30)draw_sprite(screen,deft,717,0);
    draw_sprite(screen,itens[MOLDURA],73,0);
    for(i=0; i<gamer_life[0]->get_vida(); i++)
    {
        draw_sprite(screen,itens[BARRA_VIDA],76+(i*2),7);
    }
    for(i=0; i<gamer_life[0]->get_energia(); i++)
    {
        draw_sprite(screen,itens[BARRA_KI],76+(i*2),2);
        draw_sprite(screen,itens[BARRA_KI],76+(i*2),23);
    }
    draw_sprite_h_flip(screen,itens[MOLDURA],510,0);
    for(i=0; i<gamer_life[1]->get_vida(); i++)
        draw_sprite(screen,itens[BARRA_VIDA],711-(i*2),7);
    for(i=0; i<gamer_life[1]->get_energia(); i++)
    {
        draw_sprite(screen,itens[BARRA_KI],711-(i*2),2);
        draw_sprite(screen,itens[BARRA_KI],711-(i*2),23);
    }
    draw_sprite(screen,image_items[gamer_life[0]->item_bau()],76,30);
    draw_sprite_h_flip(screen,image_items[gamer_life[1]->item_bau()],680,30);
}
bool Interface::estao_de_frente()
{
    if(gamer[0]->get_orientacao_sprite()==backp_0 && gamer[1]->get_orientacao_sprite()==backp_1)return true;
    if(gamer[0]->get_orientacao_sprite()!=backp_0 && gamer[1]->get_orientacao_sprite()!=backp_1)return true;
    return false;
}
void Interface::inicializa_sprites_gerais()
{
    gamer[0]->set_x_y(0,al_j0);
    gamer[1]->set_x_y(720,al_j1);
    itens[MOLDURA]=load_bitmap("program/img/itens/moldura_vida.pcx",NULL);
    itens[BARRA_VIDA]=load_bitmap("program/img/itens/life.pcx",NULL);
    itens[BARRA_KI]=load_bitmap("program/img/itens/ki.pcx",NULL);
    bau[0]=load_bitmap("program/img/bau/BAU_01.pcx",NULL);
    morte=load_bitmap("program/img/itens/morte.pcx",NULL);
    deft=load_bitmap("program/img/itens/ENE.pcx",NULL);
    combo=load_bitmap("program/img/itens/combo.pcx",NULL);
    load_items_bau();
    travado_1=travado_0=tempo_1=tempo_0=po_bau=carrega_ki=mostrar_bau[0]=mostrar_bau[1]=mostrar_bau[2]=0;
    golpe_pr_0=golpe_pr_1=trava_player_2=false;
    null_vector(movi_1,NUM_ANIMA,-1);
    null_vector(movi_0,NUM_ANIMA,-1);
    tmp_player_0=gamer[0]->acesso_stripe(PAR,0);
    tmp_player_1=gamer[1]->acesso_stripe(PAR,0);
    backp_0 = gamer[0]->get_orientacao_sprite();
    backp_1 = gamer[1]->get_orientacao_sprite();
    objetos_screen[FATALITY]=load_bitmap("program/img/objetos_screen/fatality.pcx",NULL);
    fundo[1]=load_bitmap("program/img/background/barra_supe_2.pcx",NULL);
}
bool Interface::da_para_atacar()
{
    /*++ -- +- -+*/
    if(colisao(x,y,x1+INCREMENTO,y1)||colisao(x+INCREMENTO,y,x1,y1))return true;//++
    if(colisao(x,y,x1-INCREMENTO,y1)||colisao(x-INCREMENTO,y,x1,y1))return true;//--
    if(colisao(x,y,x1+INCREMENTO,y1)||colisao(x-INCREMENTO,y,x1,y1))return true;//+-
    if(colisao(x,y,x1-INCREMENTO,y1)||colisao(x+INCREMENTO,y,x1,y1))return true;//-+
    return false;
}
//(movi_1[ATAC_PR]==gamer[1]->num_sprites(ATAC_PR)-1)
bool Interface::dividindo_golpes(int at,int tot)
{
    if((at==tot)||(at==tot/3))
        return true;
    return false;
}
