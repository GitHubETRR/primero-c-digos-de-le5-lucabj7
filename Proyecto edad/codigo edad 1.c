#include <stdio.h>
#define MAX_DIAS 31
#define DIC 12

int main(){
    int anioAct, mesAct, diaAct;
    int anioNac, mesNac, diaNac;
    int edad;
    int salir;
    do{
        printf("Bienvenido, ingrese los siguientes datos numericos\n");
        printf("Dia actual: ");
        scanf("%d",&diaAct);
        printf("Mes actual: ");
        scanf("%d",&mesAct);
        printf("Año actual: ");
        scanf("%d",&anioAct);
        
        //comprobaciones actuales
        while(!(0<diaAct<=MAX_DIAS)){
            printf("Ingrese un dia actual valido");
            scanf("%d",&diaAct);
        }
        while(!(0<mesAct<=DIC)){
            printf("Ingrese un mes actual valido");
            scanf("%d",&mesAct);
        }
        while(!anioAct){
            printf("Ingrese un anio actual valido");
            scanf("%d",&anioAct);
        }
        // - -
        
        printf("Ingrese sus datos personales\n");
        printf("Dia de nacimiento: ");
        scanf("%d",&diaNac);
        printf("Mes de nacimiento: ");
        scanf("%d",&mesNac);
        printf("Año de nacimiento: ");
        scanf("%d",&anioNac);
        
        //comprobaciones de nacimiento
        while (anioNac>anioAct){
            printf("Ingrese un anio de nacimiento mayor al anio actual\n");
            scanf("%d",&anioNac);
        }
        while(!(0<diaNac<=31)){
            printf("Ingrese un dia actual valido");
            scanf("%d",&diaAct);
        }
        while(!(0<mesNac<=12)){
            printf("Ingrese un mes actual valido");
            scanf("%d",&mesAct);
        }
        while(!anioNac){
            printf("Ingrese un anio actual valido");
            scanf("%d",&anioAct);
        }
        // - -
        
        edad=anioAct-anioNac;
        if(mesAct>mesNac){
            printf("Usted tiene %d años\n", edad);
        } else if(mesAct<mesNac){
            edad-=1; 
            printf("Usted tiene %d años\n", edad); 
        } else {
            if(diaAct>=diaNac){
                printf("Usted tiene %d años\n", edad);
            } else {
                edad-=1;
                printf("Usted tiene %d años\n", edad);
            }
        }
        printf("¿Desea salir? 1 para si, 0 para no\n");
        scanf("%d",&salir);
        //verificacion de que se ingreso 1 o 0
        while ((salir!=1)&&(salir!=0)){
            printf("Ingrese una opcion valida\n");
            scanf("%d",&salir);
        }
    } while (!salir);
    printf("\nAdios!");
    return 0;
}