#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define NUMMIN 10
#define NUMMAX 20
#define LARGOVEC 50
int randomizarNumero(void);
void cargarValores(int vector[]);

int main(){
    int vector[LARGOVEC];
    srand(time(NULL));
    cargarValores(vector);
    /*detectarRepeticionesMayor();*/
    return 0;
}
int randomizarNumero(void){
    int num;
    for(int i=0;i<5;i++){
        num=(rand()%(NUMMAX-NUMMIN+1))+NUMMIN;
    }
    return num;
}
void cargarValores(int vectorCargar[]){
    int i=0;
    for(i=0;i<LARGOVEC;i++){
        vectorCargar[i]=randomizarNumero();
        printf("pos: %d, val: %d \n",i ,vectorCargar[i]);
    }
}
