#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
struct lista
{
    int info;
    struct lista *sig,*ant;
}*CAB=NULL,*AUX=NULL,*Q=NULL,*P=NULL,*F=NULL,*QD=NULL,*FD=NULL;

int main() {
    void insertard(void);
    void extraerd(void);
    void visualizard(void);
    void visualizari(void);
    void eliminardespues();
    void eliminarantes();
    char opc;
    do{
        system("cls");
        printf("________________________________________________\n");
        printf("_¡¡¡MENU DE LISTA CIRCULAR DOBLEMENTE ENLAZADA!!!__\n");
        printf("___________________________________________________\n");
        printf("____________SELECCIONE UNA OPCION__________________\n");
        printf("___________________________________________________\n");
        printf("___________________________________________________\n");
        printf("__________1) INSERTAR______________________________\n");
        printf("__________2) VISUALIZAR ASCENDIENTE________________\n");
        printf("__________3) VISUALIZAR DESCENDIENTE_______________\n");
        printf("__________4) INGRESAR Y ELIMINAR SIGUIENTE_________\n");
        printf("__________5) INGRESAR Y ELIMINAR ANTERIOR__________\n");
        printf("__________6) SALIR_________________________________\n");
        printf("___________________________________________________\n");
        
        switch(opc)
        {
        case '1':
            insertard();
            break;
        case '2':
            visualizard();
            break;
        case '3':
            visualizari();
            break;
        case '4':
            eliminardespues();
            break;
        case '5':
            eliminarantes();
            break;           
        }
    } while(opc!='6');
    
    return 0;
}

void insertard(void)
{
    P=CAB;
    AUX=(struct lista *)malloc(sizeof(struct lista));
    system("cls");
    printf("INGRESE UN NUMERO ENTERO: ");
    scanf("%d",&AUX->info);
    AUX->sig=CAB;
    AUX->ant=CAB;
    F=AUX;
    if(CAB==NULL){
        CAB=AUX;
    }else{
        while (P->sig!=CAB){
            P=P->sig;
    }
    } 
        P->sig=AUX;
        AUX->ant=P;
        CAB->ant=AUX;
}

void eliminardespues(){
    int x;
    system("cls");
    printf("INGRESE UN NUMERO PARA ELIMINAR EL SIGUIENTE:");
    scanf("%d",&x);

    FD=CAB;
    QD=CAB;
    while(FD->info!=x&&FD->sig!=CAB){
    FD=FD->sig;
    }QD=FD->sig;

    if(FD->sig==CAB&&FD->info!=x){
        printf("\nEL NUMERO INGRESADO NO SE ENCUENTA EN LA LISTA");
    }else{
        if(FD->info==x){
            FD->sig=QD->sig;
            (QD->sig)->ant=FD;
            printf("\nELIMINADO %d",QD->info);
            free(Q);
        }
    }
    getch();
}


void visualizard(void)
{
    system("cls");
    if(CAB==NULL){
        printf("LISTA VACIA");
        getchar();
        return;
    }
    AUX=CAB;
    printf("LISTA:\n\n");
    while(AUX->sig!=CAB){
        printf("-> %d\n",AUX->info);
        AUX=AUX->sig;
    }
    if(AUX->sig==CAB){
        printf("-> %d\n",AUX->info);
    }
    getch();
}

void visualizari(void){
    system("cls");
    if(CAB==NULL){
        printf("LISTA VACIA");
        getchar();
        return;
    }
    AUX=CAB->ant;
    printf("LISTA:\n\n");
    do{
        printf("-> %d\n",AUX->info);
        AUX=AUX->ant;
    }while(AUX->sig!=CAB);
    getch();
}
