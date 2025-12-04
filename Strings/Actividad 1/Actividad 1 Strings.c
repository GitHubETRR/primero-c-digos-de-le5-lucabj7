#include <stdio.h>
#include <string.h>

#define MAXCADENA 101
#define CADREFERENCIA 150

int Dimension(char texto[]);
int main()
{
    int largoCad;
    char texto[MAXCADENA];
    printf("Ingrese el texto de maximo %d caracteres\n", MAXCADENA-1);
    scanf("%100[^\n]", texto); //el "[^\n]" es para que lea todos los caracteres hasta el salto de linea
    //y el 100 es para que lea hasta 100 caracteres como se especifico en el printf anterior
    largoCad=Dimension(texto);
    printf("Su cadena tiene un largo de %d caracteres\n", largoCad);
    return 0;
}
int Dimension(char texto[]){
    int largoCadena;
    largoCadena=strlen(texto); //strlen me devuelve el largo de la cadena (los caracteres escritos)
    return largoCadena;
}