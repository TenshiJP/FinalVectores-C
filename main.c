#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Funciones
void llenar_vector(int vector[],int capacidad, int longitud);
void imprimir_vector(int longitud, int vector []);
int aumentar_tamanho(int espacios);

int main()
{
    int opcion=0, espacios=9, aumento=0;//Variables para el selecci�n de men�, lonfitud del vector, y aumento de tama�o del vector.
    int vector[espacios];//vector de 10 posiciones
    do//Inicio Bucle Infinito
    {
        printf("\n\n********************** MENU **********************\n\n No.1     Llenar un Vector de Tama�o %d",espacios+1);
        printf("\n No.2     Imprimir el Vector");
        printf("\n No.3     Aumentar Tama�o del Vector Actual");
        printf("\n No.4     Salir\n Ingrse su opcion: ");
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                printf("\n\t***** LLENAR VECTOR *****\n");
                llenar_vector(vector,1,espacios);
                printf("\n");
                break;
            case 2:
                imprimir_vector(espacios,vector);
                break;
            case 3:
                aumento=aumentar_tamanho(espacios);
                espacios=aumento;//Se declara el nuevo tama�o para el vector
                printf("\nCOMPROBACION: ");
                imprimir_vector(espacios,vector);
        }

    }while(opcion!=4);//Fin Bucle Infinito
    return 0;
}

void llenar_vector(int vector [],int capacidad, int longitud)//Funci�n para ingresar valores al vector
{
    int numero=0;
    if(capacidad == (longitud+2))//m�todo recursivo
        return;
    else
    {
        printf("\nNo.%d Ingrese el valor que desee al Vector: ",capacidad);
        scanf("%d",&numero);
        vector[capacidad-1] = numero;
        llenar_vector(vector,capacidad+1,longitud);
    }
}

void imprimir_vector(int longitud, int vector [])//Funci�n para imprimir vector
{

    printf("\n\t***** IMPRIMIR VECTOR *****\n\nEl vector posee los siguientes elmentos: \n\n");
    for (int i=0;i<(longitud+1);i++)
    {
        printf("El elemento No.%d es = %d \n", i+1, vector[i]);
    }
    printf("\n");
}

int aumentar_tamanho(int espacios)//Funci�n para aumentar tama�o del vector
{
    int valor=0;
    printf("\n\t***** AUMENTAR TAMA�O AL VECTOR *****\n\n");
    printf("\nIngrese el nuevo tama�o del vector: ");
    scanf("%d",&valor);//guarda el posible tama�o del nuevo vector
    if (valor<=(espacios+1))
    {
        printf("\n\n#ERROR: El tama�o ingresado es igual o menor a la del vector actual, se conservara la capacidad actual\n");
    }
    else
    {
        printf("\n\nSe aumento el tama�o, el nuevo tama�o es: %d\n",valor);
        espacios=valor-1;
    }
    return espacios;
}
