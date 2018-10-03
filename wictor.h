//-------------------------------------------------------------------------------------//
// Biblioteca para facilitar e evitar bugs ao programar em c                           //
//-------------------------------------------------------------------------------------//
// Nome: 		       WictorLib                                                       //
// Author:             Wictor de Oliveira Dias Chaves (wictor@hotmail.com.br)          //
// Versão			   last ;)                                                         //
// Date:               12.06.2015                                                      //
//-------------------------------------------------------------------------------------//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <sys/time.h>
#include <math.h>

//-------------------------------------------------------------------------------------//
// SISTEMA operacional                                                                 //
//                                                                                     //
//  1 - Escolha Manualmente:                                                           //
//  int SISTEMA = 1; //0 - para Linux, 1 para Windows                                  //
//                                                                                     //
//-------------------------------------------------------------------------------------//
//    __linux__       Defined on Linux                                                 //
//    __unix__        Defined on Unix                                                  //
//    _WIN32          Defined on Windows                                               //
//    __sun           Defined on Solaris                                               //
//    __FreeBSD__     Defined on FreeBSD                                               //
//    __NetBSD__      Defined on NetBSD                                                //
//    __OpenBSD__     Defined on OpenBSD                                               //
//    __APPLE__       Defined on Mac OS X                                              //
//    __hpux          Defined on HP-UX                                                 //
//    __osf__         Defined on Tru64 UNIX (formerly DEC OSF1)                        //
//    __sgi           Defined on Irix                                                  //
//    _AIX            Defined on AIX                                                   //
//-------------------------------------------------------------------------------------//
//  2 - Escolha Automatica:                                                            //
#ifdef __linux__                                                                       //
#define SISTEMA 0                                                                      //
#elif _WIN32                                                                           //
#define SISTEMA 1                                                                      //
#else                                                                                  //
#define SISTEMA 1                                                                      //
#error "OS not supported!"                                                             //
#endif                                                                                 //
//-------------------------------------------------------------------------------------//

//Tipos -----------------------------------------------------------------------------------
#define true 1
#define false 0
typedef char *string;

//Saidas ----------------------------------------------------------------------------------
char _saida[1000];

//Utilitarios -----------------------------------------------------------------------------
int lengthInt(int valor)
{
    int d = 1;
    while((pow(10, d)-1) < valor)
    {
        d++;
    }
    return d;
}
int lengthFloat(float valor)
{
    int d = 1;
    while((pow(10, d)-1) < valor)
    {
        d++;
    }
    return d;
}
int lengthStr(char *valor)
{
    return strlen(valor);
}
int tipoChar(char valor)
{
    //Inteiro
    if(valor >= 48 && valor <= 57)
    {
        return 1;
    }
    //Char minusculo
    if(valor >= 97 && valor <= 122)
    {
        return 2;
    }
    //Char maiusculo
    if(valor >= 65 && valor <= 90)
    {
        return 3;
    }
    return 4;
}
int tipoStr(char *valor)
{
    // 1 - Inteiro com 1 digito
    // 2 - Char
    // 3 - Inteiro com mais de 1 digito
    // 4 - String
    // 5 - Float

    int tipoFloat = 0;
    int inicial = 0;

    //Verifica se o numero e negativo
    if(valor[0] == 45)
    {
        inicial = 1;
    }
    if(lengthStr(valor) == 1)
    {
        return tipoChar(valor[0]);
    }
    else if(lengthStr(valor) > 1)
    {
        for(int i = inicial; i < lengthStr(valor); i++)
        {
            if(tipoChar(valor[i]) >= 2)
            {
                if(valor[i] == 46)  //Verifica se existe ponto(.)
                {
                    tipoFloat++;
                }
                else
                {
                    return 4;
                }
            }
        }
        if(tipoFloat == 1)
        {
            return 5;
        }
        else if(tipoFloat > 1)   //Se tiver mais de 1 ponto e uma string
        {
            return 4;
        }
        else
        {
            return 3;
        }
    }
    return 4;
}
//Conversão -----------------------------------------------------------------------------
string int2str(int valor)
{
    //Suporta ate 2.147.483.647
    sprintf(_saida, "%d", valor);
    return _saida;
}
char int2chr(int valor)
{
    char saida;
    saida = (char)valor + 48;
    return saida;
}
int str2int(string valor)
{
    return atoi(valor);
}
float str2float(string valor)
{
    return atof(valor);
}
int chr2int(char valor)
{
    int saida = (int)valor;
    saida = saida - 48;
    return saida;
}
int bin2dec(int valor)
{
    string valBin = int2str(valor);
    int resultado = 0;
    for(int i = lengthStr(valBin)-1;i >= 0;i--){
        if(valBin[i] == '1'){
            resultado = pow(2,(double)(lengthStr(valBin)-i-1)) + resultado;
        }
    }
    return resultado;
}
int dec2bin(int valor)
{
    int i = 0;
    float resultado = 0;
    while(valor >= 1){
        resultado = (( (valor % 2) * pow(10,i) ) + resultado);
        valor = valor / 2;
        i++;
    }
    return (int)resultado;
}
//Entrada e saida de dados (Int - Double - Char - String)--------------------------------
//                          inputInt, inputDouble, inputChar, inputStr
int lerString(char **valor)
{
    int i = 0;
    char letra,s[1000];
    for (i = 0; i < (1000 - 1); i++)
    {
        letra = fgetc(stdin);
        if ((letra == '\n') && (i == 0))
        {
            i = i - 1;
            continue;
        }
        if (letra == '\n')
            break;
        s[i] = letra;
    }
    s[i] = 0;
    *valor = s;
    return (i);
}
void lerChar(char *s)
{
    *s = fgetc(stdin);
    if (*s == '\n')
    {
        *s = fgetc(stdin);
    }
}
void inputInt(string msg,int *valor)
{
    printf("%s", msg);
    scanf("%d",&*valor);
}
void inputDouble(string msg,double *valor)
{
    printf("%s", msg);
    scanf("%lf",&*valor);
}
void inputFloat(string msg,float *valor)
{
    printf("%s", msg);
    scanf("%f",&*valor);
}
void inputChar(string msg, char *valor)
{
    printf("%s", msg);
    lerChar(&*valor);
}
void inputStr(string msg, string *valor)
{
    printf("%s", msg);
    lerString(&*valor);
}
//Tela e eveitos visuais -------------------------------------------------------------------
void limparTela()
{
    if(SISTEMA == 0)
    {
        system("clear");//Linux
    }
    else
    {
        system("cls");//Windows
    }
}
void pausar(char *s)
{
    *s = fgetc(stdin);
    while(*s != '\n')
    {
        *s = fgetc(stdin);
    }
}
void Continue()
{
    if(SISTEMA == 0)
    {
        printf("\nPressione qualquer tecla para continuar. . .");
        getchar();
        + scanf("c\n");
        //Metodo alternativo
        /*system("read -p \"Pressione qualquer tecla para continuar. . .\" saindo");//Linux*/
    }
    else
    {
        system("pause");//Windows
    }
}
//Tratamento de String ---------------------------------------------------------------------
string upCase(string valor)
{
    int tamanho = strlen(valor);
    for(int x=0; x<tamanho; x++)
    {
        if(valor[x] >= 97 && valor[x] <= 122)
        {
            _saida[x] = valor[x] - 32;
        }
        else
        {
            _saida[x] = valor[x];
        }
    }
    return _saida;
}
string downCase(string valor)
{
    int tamanho = strlen(valor);
    for(int x=0; x<tamanho; x++)
    {
        if(valor[x] >= 65 && valor[x] <= 90)
        {
            _saida[x] = valor[x] + 32;
        }
        else
        {
            _saida[x] = valor[x];
        }
    }
    return _saida;
}
char downCaseChar(char valor)
{
    if(valor >= 65 && valor <= 90)
    {
        valor = valor + 32;
    }
    return valor;
}
char upCaseChar(char valor)
{
    if(valor >= 97 && valor <= 122)
    {
        valor = valor + 32;
    }
    return valor;
}
int cmpStr(string valor1,string valor2)
{
    int tamanho;

    //Pega quantidade de digitos
    int t1 = tamanho = strlen(valor1);
    int t2 = strlen(valor2);

    //Saber qual a menor String
    if(t1 > t2)
    {
        tamanho = t2;
    }

    //Verifica todas as letras da string
    for(int x=0; x<tamanho; x++)
    {
        //Se a primeira for menor
        if(downCaseChar(valor1[x]) < downCaseChar(valor2[x]))
        {
            return 1;
        }
        //Se a primeira for maior
        if(downCaseChar(valor1[x]) > downCaseChar(valor2[x]))
        {
            return -1;
        }
    }
    //definição por numero de caracteres
    if(t1 < t2)
    {
        return 1;
    }
    if(t1 > t2)
    {
        return -1;
    }

    return 0;
}
