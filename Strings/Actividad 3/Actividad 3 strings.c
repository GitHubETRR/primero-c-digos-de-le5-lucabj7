#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LARGOCAD 101
#define VOCALESTOT 5
void ingresarTexto(char textoInicial[]);
void pasaMinuscula(char textoInicial[], char textoFinal[]);
int vocales(char textoFinal[], char vocalesTodas[]);
int main()
{
    char textoInicial[LARGOCAD];
    char textoFinal[LARGOCAD];
    char vocalesTodas[]="aeiou";
    int cantVocales;
    ingresarTexto(textoInicial);
    pasaMinuscula(textoInicial, textoFinal);
    printf("Su texto en minuscula es: %s\n", textoFinal);
    cantVocales=vocales(textoFinal, vocalesTodas);
    printf("Su texto tiene %d vocales\n", cantVocales);
    return 0;
}
void ingresarTexto(char textoInicial[]){
    printf("Ingrese su texto a transformar en minuscula con un maximo de 100 caracteres\n");
    scanf("%100[^\n]", textoInicial);
}
void pasaMinuscula(char textoInicial[], char textoFinal[]){
    for(int i=0;i<LARGOCAD;i++){
        textoFinal[i]=tolower(textoInicial[i]);
    }
}
int vocales(char textoFinal[], char vocalesTodas[]){
    int cantVocalesEnCad=0;
    for(int i=0;i<LARGOCAD;i++){
        if(textoFinal[i]=='a'||textoFinal[i]=='e'||textoFinal[i]=='i'||textoFinal[i]=='o'||textoFinal[i]=='u'){
            cantVocalesEnCad++;
        }
    }
    return cantVocalesEnCad;
}