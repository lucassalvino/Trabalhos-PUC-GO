template<class TIPO>
TIPO Operadores<TIPO>::somar(TIPO a, TIPO b)
{
    //recebe a e b, e retorna o resultado de a+b
    return a+b;
}

template<class TIPO>
TIPO Operadores<TIPO>::subtrair(TIPO a, TIPO b)
{
    //recebe a e b, e retorna o resultado de a-b
    return a-b;
}

template<class TIPO>
TIPO Operadores<TIPO>::dividir(TIPO a, TIPO b)
{
    //recebe a e b, e retorna o resultado de a/b
    if(b==0)throw string("DIVISAO POR ZERO");
    return a/b;
}

template<class TIPO>
double Operadores<TIPO>::dividirRetornoPontoFlutuane(TIPO a, TIPO b)
{
    //recebe a e b, e retorna o resultado de (double)a/b
    if(b==0)throw string("DIVISAO POR ZERO");
    return (double)a/b;
}

template<class TIPO>
TIPO Operadores<TIPO>::multiplicar(TIPO a, TIPO b)
{
    //recebe a e b e retorna a*b
    return a*b;
}

template<class TIPO>
TIPO Operadores<TIPO>::potencia(TIPO a, TIPO b)
{
    //recebe a e b, retorna a^b
    return pow(a,b);
}

