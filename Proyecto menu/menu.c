#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define HABSMAX 600
#define MAXSERVS 3
#define AMBIENTES 3
#define SUCIEDADMIN 10
#define MAXCAMARAS 2
#define MINCAMARAS 1
#define PUNTOSANIM1 3
#define CARACTANIM2 4

int ingreso (void);
void servRealizado(void);
int seleccionServ(void);
void serv0(void);
void serv1(void);
void serv2(void);
void serv3(void);
void lucesCocinaComedor(void);
void lucesBaño(void);
void lucesHab(void);
int salida(void);
void reinicioCamara(void);
void despedida(int);

int main(){
    int habServ;
    int hab;
    
    hab=ingreso();
    servRealizado();
    despedida(hab);
    return 0;
}
int ingreso(void){
    int hab;
    printf("Bienvenido al sistema de servicio del hotel Epic\n");
    printf("Ingrese el numero de la habitacion a asistir (1-600)\n");
    scanf("%d",&hab);
    if(hab>HABSMAX || hab<=0){
       do{
        printf("Ingrese un numero de habitacion valido\n");
        scanf("%d",&hab);
        }while((hab>HABSMAX) || (hab<=0)); 
    }
    return (hab);
}
int salida(void){
    int salir;
    printf("\nDesea salir de la interfaz general?\n");
    printf("|0- no\n|1- si\n");
    scanf("%d",&salir);
    if(salir!=1 && salir!=0){
        do{
        printf("Ingrese una opcion valida\n");
        scanf("%d",&salir);
        }while(salir!=1 && salir!=0);
    }
    if(salir){
        system("clear");
    }
    return salir;
}
void servRealizado(void){
    int salir;
    int habServ;
    int cantServicios;
    do{
        habServ=seleccionServ();
        switch(habServ){
            case 0:
            serv0();
            break;
            case 1:
            serv1();
            break;
            case 2:
            serv2();
            break;
            case 3:
            serv3();
            break;
        } 
        salir=salida();
    }while (!salir);
    
    return;
}
int seleccionServ(void){
    int habServ;
    printf("Seleccione el servicio a realizar\n");
    printf("|0- Verificacion de temperaturas\n");
    printf("|1- Control de luces\n");
    printf("|2- Control de limpieza\n");
    printf("|3- Control de camaras\n");
    scanf("%d",&habServ);
    if(habServ<0 || habServ>MAXSERVS){
        do {
        printf("Ingrese una opcion valida\n");
        scanf("%d",&habServ);
        }while(habServ<0 || habServ>MAXSERVS); 
    }
    return habServ;
}
void serv0(void){
    int temp[AMBIENTES];
    int sumaTemp=0;
    float promTemp;
    printf("Para el control de temperaturas de la habitacion se debe evaluar los datos registrados por los sensores\n");
    printf("Ingrese las temperaturas de los 3 ambientes en grados Celsius\n");
    for (int i=0;i<AMBIENTES;i++){
        printf("Ambiente %d: \n", i + 1);
        scanf("%d",&temp[i]);
        sumaTemp+=temp[i];
    }
    promTemp=(float)sumaTemp/AMBIENTES;
    printf("La temperatura promedio en este momento es de %.1f°C \n",promTemp);
    return;
    
}
void serv1(void){
    int luzSelecc;
    do{
        printf("Seleccionar la accion a realizar\n");
        printf("|0- Luces cocina-comedor\n");
        printf("|1- Luces baño\n");
        printf("|2- Luces habitacion\n");
        printf("|3- Salir\n");
        scanf("%d", &luzSelecc);
        if(luzSelecc<0 || luzSelecc>3){ //comprobacion de que luzSelecc esta entre 0-3
            do{
                printf("Ingrese una opcion valida\n");
                scanf("%d",&luzSelecc);
            } while(luzSelecc<0 || luzSelecc>3);
        }
        srand(time(NULL));
        switch(luzSelecc){
            case 0:
            lucesCocinaComedor();
            break;
            case 1:
            lucesBaño();
            break;
            case 2:
            lucesHab();
            break;
        } 
    } while(luzSelecc!=3);
    return;
}
void lucesCocinaComedor(void){
    if((rand()%2)==1){
        printf("Las luces de la cocina comedor estan prendidas\n");
    } else {
        printf("Las luces de la cocina comedor estan apagadas\n");
    }
}
void lucesBaño(void){
    if((rand()%2)==1){
        printf("Las luces del baño estan prendidas\n");
    } else {
        printf("Las luces del baño estan apagadas\n");
    }
}
void lucesHab(void){
    if((rand()%2)==1){
        printf("Las luces de la habitacion estan prendidas\n");
    } else {
        printf("Las luces de la habitacion estan apagadas\n");
    }
}
void serv2(void){
    int porcSuciedad;
    porcSuciedad=rand()%100;
    printf("El cliente reporto una suciedad del %d porciento\n", porcSuciedad);
    if(porcSuciedad>SUCIEDADMIN){
        printf("Se requiere una limpieza\n");
    } else {
        printf("La suciedad es menor al porcentaje necesario para requerir de una limpieza\n");
    }
}
void serv3(void){
    int estadoCamara[MAXCAMARAS];
    int camara=MINCAMARAS;
    int reinicio;
    printf("Para el control de camaras es necesario hacer una verificacion inicial de funcionamiento\n");
    for(int i=0;i<MAXCAMARAS;i++){
        camara+=i;
        estadoCamara[i]=rand()%2;
        printf("La camara %d esta en estado logico %d \n", camara, estadoCamara[i]);
        if(estadoCamara[i]==0){
            printf("Necesita ser reiniciada para volver a operar correctamente, desea realizar esta accion?\n");
            printf("|0- no\n|1- si\n");
            scanf("%d",&reinicio);
            if(reinicio){
                reinicioCamara();
            } else {
                printf("Sera requerida una revisacion por parte del equipo de mantenimiento\n");
            }
        }
    }
}
void reinicioCamara(void){
    for(int i1=0;i1<PUNTOSANIM1; i1++){
        printf(". ");
        fflush(stdout); //obliga al sistema a escribir el punto en el terminal sin que tenga que terminar todo el procesamiento
        sleep(1);     
    }
    printf("\nReiniciando");
    for(int i2=0;i2<CARACTANIM2;i2++){
        printf(".");
        fflush(stdout);
        sleep(1.5);
    }
    printf("\nReinicio correctamente realizado");
}
void despedida(int hab){
    printf("\nSe han realizado servicios a la habitacion %d \n", hab);
    printf("Muchas gracias por su labor para mantener al hotel en sus mas altos estandares\n");
    printf("Hotel Epic.\n");
    return;
}