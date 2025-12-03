#include <stdio.h>
#include <math.h>

#define TAMANOVECS 2
#define MODULO 0
#define ANGULO 1
#define EJEX 0
#define EJEY 1

void ingresarVectores(int vectorPol1[], int vectorPol2[]);
void calcularCoordsVecs(int vectorPol1[], int vectorPol2[], float vCart1[], float vCart2[]);
float productoEscalarVecs(float vCart1[], float vCart2[]);

int main()
{
	int vectorPol1[TAMANOVECS], vectorPol2[TAMANOVECS]; //vectorPoln[0]=modulo, vectorPoln[1]=angulo
	//van a tener tamaC1o 2 para poder guardar angulo y modulo
	float vCart1[TAMANOVECS], vCart2[TAMANOVECS]; //vCartn[0]=X, vCartn[1]=Y
	//tambien tendran tamaC1o 2 para poder guardar coordenadas x e y
	float prodEscalar;
	ingresarVectores(vectorPol1, vectorPol2);
	calcularCoordsVecs(vectorPol1, vectorPol2, vCart1, vCart2);
	prodEscalar=productoEscalarVecs(vCart1, vCart2);
	printf("El producto escalar entre los vectores 1 y 2 es: %.2f", prodEscalar);
	return 0;
}

void ingresarVectores(int vectorPol1[], int vectorPol2[]) {
	float moduloVec1, anguloVecGrados1, anguloVecRadianes1;
	float moduloVec2, anguloVecGrados2, anguloVecRadianes2;
	//vector 1:
	printf("Ingrese el modulo de su vector 1: ");
	scanf("%f", &moduloVec1);
	while(moduloVec1<0) {
		printf("\nIngrese un modulo valido\n");
		scanf("%f", &moduloVec1);
	}
	vectorPol1[MODULO]=moduloVec1;
	printf("\nIngrese el angulo de su vector 1 en grados: ");
	scanf("%f", &anguloVecGrados1);
	anguloVecRadianes1=anguloVecGrados1*(M_PI/180);
	vectorPol1[ANGULO]=anguloVecRadianes1;

	//vector 2:
	printf("\nIngrese el modulo de su vector 2: ");
	scanf("%f", &moduloVec2);
	while(moduloVec2<0) {
		printf("\nIngrese un modulo valido\n");
		scanf("%f", &moduloVec2);
	}
	vectorPol2[MODULO]=moduloVec2;
	printf("\nIngrese el angulo de su vector 2 en grados: ");
	scanf("%f", &anguloVecGrados2);
	anguloVecRadianes2=anguloVecGrados2*(M_PI/180);
	vectorPol2[ANGULO]=anguloVecRadianes2;
}
void calcularCoordsVecs(int vectorPol1[], int vectorPol2[], float vCart1[], float vCart2[]) {
	//vector 1
	float coordXVec1=vectorPol1[MODULO]*cos(vectorPol1[ANGULO]);
	float coordYVec1=vectorPol1[MODULO]*sin(vectorPol1[ANGULO]);
	vCart1[EJEX]=coordXVec1;
	vCart1[EJEY]=coordYVec1;
	//vector 2
	float coordXVec2=vectorPol2[MODULO]*cos(vectorPol2[ANGULO]);
	float coordYVec2=vectorPol2[MODULO]*sin(vectorPol2[ANGULO]);
	vCart2[EJEX]=coordXVec2;
	vCart2[EJEY]=coordYVec2;
}
float productoEscalarVecs(float vCart1[], float vCart2[]) {
	float prodTotalX;
	float prodTotalY;
	float sumaTotal;
	prodTotalX=vCart1[EJEX]*vCart2[EJEX];
	prodTotalY=vCart1[EJEY]*vCart2[EJEY];
	sumaTotal=prodTotalX+prodTotalY;
	return sumaTotal;
}
