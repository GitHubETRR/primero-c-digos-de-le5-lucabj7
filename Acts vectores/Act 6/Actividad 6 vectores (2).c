#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define NUMMAX 90
#define NUMMIN 20
#define LARGOVEC 20

void CargarVector(int vector1[], int vector2[]);
void InvertirVector(int vector1[], int vector2[]);
void MostrarVector(int vector1[], int vector2[]);
int main()
{
	int vector1[LARGOVEC];
	int vector2[LARGOVEC];
	srand(time(NULL));
	CargarVector(vector1, vector2);
	InvertirVector(vector1, vector2);
	MostrarVector(vector1, vector2);
	return 0;
}
int randomNum(void) {
	int num;
	num=(rand()%(NUMMAX-NUMMIN+1))+NUMMIN;
	return num;
}
void CargarVector(int vector1[], int vector2[]) {
	for(int i=0; i<LARGOVEC; i++) {
		vector1[i]=randomNum();
	}
}
void InvertirVector(int vector1[], int vector2[]){
    for(int i=0;i<LARGOVEC;i++){
        int posFin=LARGOVEC-1-i;
        vector2[i]=vector1[posFin];
    }
}
void MostrarVector(int vector1[], int vector2[]){
    printf("Valores del vector 1: \n");
    for(int i=0;i<LARGOVEC;i++){
        printf("posicion: %d, valor: %d\n", i, vector1[i]);
    }
    printf("Valores del vector 2: \n");
    for(int i=0;i<LARGOVEC;i++){
        printf("posicion: %d, valor: %d\n", i, vector2[i]);
    }
}