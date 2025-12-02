#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define NUMMIN 10
#define NUMMAX 41
#define LARGOVEC 100

void cargarValores(int vector[]);
int randomizarNumero(void);
int detectarValorMax(int vector[]);
int detectarValorMin(int vector[]);
void encontrarRepeticionesMax(int vector[],int valMax);
int main()
{
    int vector[LARGOVEC];
    srand(time(NULL));
    cargarValores(vector);
    int valMax=detectarValorMax(vector);
    int valMin=detectarValorMin(vector);
    printf("El valor maximo es: %d \nEl valor minimo es: %d \n", valMax, valMin);
    encontrarRepeticionesMax(vector,valMax);
    return 0;
}
int randomizarNumero(void){
    int num;
    num=(rand()%(NUMMAX-NUMMIN))+NUMMIN;
    return num;
}
void cargarValores(int vectorCargar[]){
    int i=0;
    for(i=0;i<LARGOVEC;i++){
        vectorCargar[i]=randomizarNumero();
        //par corroborar que se randomizan los 100 valores, se puede sacar el comentario
        //printf("pos: %d, val: %d \n",i ,vectorCargar[i]);
    }
}
int detectarValorMax(int vector[]){
    int i=1;
    int mayor=vector[0];
    for(i;i<LARGOVEC;i++){
        if(vector[i]>mayor){
            mayor=vector[i];
        }
    }
    return mayor;
}
int detectarValorMin(int vector[]){
    int i=1;
    int menor=vector[0];
    for(i;i<LARGOVEC;i++){
        if(vector[i]<=menor){
            menor=vector[i];
        }
    }
    return menor;
}
void encontrarRepeticionesMax(int vector[],int valMax){
    int contador=0;
    for(int i=1;i<LARGOVEC;i++){
        if(vector[i]==valMax){
            ++contador;
        }
    }
    printf("La cantidad de veces que se repite el mayor es: %d", contador);
}