#include"item.h"
class Item_void:public Item
{
public:
    Item_void()
    {
        vida_i=0,destreza_i=0,energia_i=0,forca_i=0;
        //item=load_bitmap("program/img/itens/void.pcx",NULL);
        item=NADA;
        dano = false;
    }
};
class Item_casco_tartaruga:public Item
{
public:
    Item_casco_tartaruga()
    {
        vida_i=0,destreza_i=4,energia_i=0,forca_i=20;
        //item=load_bitmap("program/img/itens/casco_tartaruga.pcx",NULL);
        item=CASCO_TARTARUGA;
        dano = false;
    }
};
class Item_espada:public Item
{
public:
    Item_espada()
    {
        vida_i=0,destreza_i=2,energia_i=5,forca_i=40;
        item=ESPADA;
        //item=load_bitmap("program/img/itens/espada_z.pcx",NULL);
        dano = false;
    }
};
class Item_lua_cheia:public Item
{
public:
    Item_lua_cheia()
    {
        vida_i=100,destreza_i=-5,energia_i=100,forca_i=3000;
        item=LUA_CHEIA;
        //item=load_bitmap("program/img/itens/lua_cheia.pcx",NULL);
        dano = false;
    }
};
class Item_mestre_kame:public Item
{
public:
    Item_mestre_kame()
    {
        vida_i=4,destreza_i=-2,energia_i=15,forca_i=300;
        item=MESTRE_KAME;
        //item=load_bitmap("program/img/itens/mestre_kame.pcx",NULL);
        dano = false;
    }
};
class Item_nuvem_voadora:public Item
{
public:
    Item_nuvem_voadora()
    {
        vida_i=0,destreza_i=-15,energia_i=25,forca_i=0;
        item=NUVEM_VOADORA;
        //item=load_bitmap("program/img/itens/nuvem_voadora.pcx",NULL);
        dano = false;
    }
};
class Item_peixe:public Item
{
public:
    Item_peixe()
    {
        vida_i=20,destreza_i=0,energia_i=10,forca_i=0;
        item=PEIXE;
        //item=load_bitmap("program/img/itens/peixe.pcx",NULL);
        dano = false;
    }
};
class Item_semente_dos_deuses:public Item
{
public:
    Item_semente_dos_deuses()
    {
        vida_i=100,destreza_i=0,energia_i=100,forca_i=0;
        item= SEMENTE_DOS_DEUSES;
        //item=load_bitmap("program/img/itens/semente_dos_deuses.pcx",NULL);
        dano = false;
    }
};
class Item_senhor_kaio:public Item
{
public:
    Item_senhor_kaio()
    {
        vida_i=10,destreza_i=-10,energia_i=10,forca_i=900;
        item = SENHOR_KAIO;
        ///item=load_bitmap("program/img/itens/senhor_kaio.pcx",NULL);
        dano = false;
    }
};
class Item_zeni:public Item
{
public:
    Item_zeni()
    {
        vida_i=0,destreza_i=0,energia_i=100,forca_i=0;
        item=ZENI;
        //item=load_bitmap("program/img/itens/zeni.pcx",NULL);
        dano = false;
    }
};


class Item_titi:public Item
{
public:
    Item_titi()
    {
        vida_i=15,destreza_i=0,energia_i=20,forca_i=0;
        item=TITI;
        //item=load_bitmap("program/img/itens/titi.pcx",NULL);
        dano = true;
    }
};
class Item_bulma:public Item
{
public:
    Item_bulma()
    {
        vida_i=15,destreza_i=0,energia_i=20,forca_i=0;
        item=BULMA;
        //item=load_bitmap("program/img/itens/bulma.pcx",NULL);
        dano = true;
    }
};
class Item_lanchi:public Item
{
public:
    Item_lanchi()
    {
        vida_i=15,destreza_i=0,energia_i=20,forca_i=0;
        item=LANCHI;
        //item=load_bitmap("program/img/itens/lanchi.pcx",NULL);
        dano = true;
    }
};
class Item_babidi:public Item
{
public:
    Item_babidi()
    {
        vida_i=30,destreza_i=0,energia_i=50,forca_i=0;
        item=BABIDI;
        //item=load_bitmap("program/img/itens/babidi_r_energia.pcx",NULL);
        dano = true;
    }
};
class Item_cell:public Item
{
public:
    Item_cell()
    {
        vida_i=40,destreza_i=0,energia_i=90,forca_i=0;
        item=CELL;
        //item=load_bitmap("program/img/itens/babidi_r_energia.pcx",NULL);
        dano = true;
    }
};
