#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LARGOCAD 101

void ingresarTexto(char textoInicial[]);
void pasaMinuscula(char textoInicial[], char textoFinal[]);
int main()
{
    char textoInicial[LARGOCAD];
    char textoFinal[LARGOCAD];
    ingresarTexto(textoInicial);
    pasaMinuscula(textoInicial, textoFinal);
    printf("Su texto en minuscula es: %s\n", textoFinal);
    return 0;
}
void ingresarTexto(char textoInicial[]){
    printf("Ingrese su texto a transformar en minuscula con un maximo de 100 caracteres\n");
    scanf("%100[^\n]", textoInicial);
}
void pasaMinuscula(char textoInicial[], char textoFinal[]){
    for(int i=0;i<LARGOCAD;i++){
        textoFinal[i]=tolower((unsigned char)textoInicial[i]);
    }
}