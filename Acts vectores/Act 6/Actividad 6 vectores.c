#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define NUMMAX 90
#define NUMMIN 20
#define LARGOVEC 20

void CargarVector(int vector[]);
int main()
{
	int vector[LARGOVEC];
	srand(time(NULL));
	CargarVector(vector);
	//InvertirVector();
	//MostrarVector();
	return 0;
}
int randomNum(void) {
	int num;
	num=(rand()%(NUMMAX-NUMMIN+1))+NUMMIN;
	return num;
}
void CargarVector(int vector[]) {
	int i=0;
	for(i; i<LARGOVEC; i++) {
		vector[i]=randomNum();
		//para corroborar, sacar comentario
		printf("pos: %d, val: %d \n",i,vector[i]);
	}
}