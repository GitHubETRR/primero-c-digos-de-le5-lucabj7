#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define NUMMIN 10
#define NUMMAX 21
#define LARGOVEC 50
int randomizarNumero(void);
void cargarValores(int vector[]);
int detectarRepeticionesMayor(int vector[]);
int main(){
    int vector[LARGOVEC];
    int repeticiones;
    srand(time(NULL));
    cargarValores(vector);
    repeticiones=detectarRepeticionesMayor(vector);
    printf("el mayor numero se repite %d veces", repeticiones);
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
        printf("pos: %d, val: %d \n",i ,vectorCargar[i]);
    }
}
int detectarRepeticionesMayor(int vector[]){
    int mayor=vector[0];
    int contador=1; //ya que siempre hay por lo menos 1 mayor a todos
    for(int i=1;i<LARGOVEC;i++){
        if(vector[i]>mayor){
            mayor=vector[i];
            contador=1;
        } else if(vector[i]==mayor){
            contador++;
        }
    }
    printf("El mayor numero es: %d \n", mayor);
    return contador;
}
