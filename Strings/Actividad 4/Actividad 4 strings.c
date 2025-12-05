#include <stdio.h>
#include <string.h>

#define LARGOMAX 101

void Invertir(char txtNormal[], char txtInvertido[]);
int main()
{
    char txtNormal[LARGOMAX];
    char txtInvertido[LARGOMAX];
    printf("Ingrese su texto con un maximo de 100 caracteres\n");
    scanf("%100[^\n]", txtNormal);
    Invertir(txtNormal, txtInvertido);
    printf("Su texto invertido es: \n%s\n", txtInvertido);
    return 0;
}
void Invertir(char txtNormal[], char txtInvertido[]){
    int largoCadena=strlen(txtNormal);
    txtInvertido[largoCadena]='\0'; //agrego manualmente el null para que el printf del final sepa hasta donde escribir
    for(int i=0;i<largoCadena;i++){
        int posicionFinal=largoCadena-1-i; //posicion final del caracter a invertir
        txtInvertido[i]=txtNormal[posicionFinal];
    }
}