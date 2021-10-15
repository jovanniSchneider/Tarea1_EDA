#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"


//DECLARACION DE FUNCIONES 
int detectarSO();
void limpiarConsola();
song * leerListado();
song * quicksort(song * lista, int inicio, int fin);
int particiona(song * lista, int inicio, int fin);
void swap(song * cancion1,song * cancion2);

//Entrada: No recibe
//Salida: Un entero, 0 para windows, 1 Para Linux o MAC
//Función: Detecta el sistema operativo en el que se está trabajando

int detectarSO()
{
#if defined(_WIN32)
#define SISTEMA 0
#else
#define SISTEMA 1
#endif
    return SISTEMA;
}

//------------------------------------------------------

//Entrada: No recibe
//Salida: No retorna
//Función: Detecta el sistema operativo en uso y limpia la consola
void limpiarConsola()
{
    int sistema = detectarSO();
    switch (sistema)
    {
    case 0:
        system("cls");
        break;
    case 1:
        system("clear");
        break;
    }
}

void swap(song *cancion1,song *cancion2){
    song temporal = *cancion1;
    *cancion1 = *cancion2;
    *cancion2 = temporal;
}

int particiona(song * lista, int inicio, int fin){
    int x = lista[inicio].kind;
    int i = inicio-1;
    for (int j = inicio; j < fin-1; j++)
    {
        if (lista[j].kind <= x)
        {
            i++;
            swap(&lista[i],&lista[j]);
        }
    }
    swap(&lista[i+1],&lista[fin]);
    return(i+1);
}





song * quicksort(song * lista, int inicio, int fin){
    if (inicio<fin)
    {
            int pivote = particiona(lista,inicio,pivote);
            quicksort(lista,inicio,pivote-1);
            quicksort(lista,pivote+1,fin);
    }
    
}
//------------------------------------------------------

//Entrada: No recibe
//Salida: Un arreglo de estructuras del tipo song
//Función: Lee el archivo listado.in y lo ordena de menor a mayor (indice) por genero musical

song * leerListado(){
    FILE *archivo = fopen("listado.in", "r");
    char strAux[150];
    int cantidad;
    cantidad = atoi(fgets(strAux,150,archivo));
    printf("cantidad: %d\n",cantidad);
    song * listado = (song*)malloc(sizeof(song)*cantidad);
    for(int i = 0; i < cantidad;i++){
        fgets(strAux,150,archivo);
        listado[i].name = strtok(strAux," ");
        listado[i].kind = atoi(strtok(NULL," "));
        listado[i].duration[0] = atoi(strtok(NULL,":"));
        listado[i].duration[1] = atoi(strtok(NULL," "));
        listado[i].autor = strtok(NULL,"\n");
    }
    quicksort(listado,0,cantidad);
    printf("-------------Quicksort----------------\n");
    for (int i = 0; i < cantidad; i++)
    {
        printf("Name: %s\nKind: %d\nDuration: %d:%d\nAutor: %s\n",listado[i].name,listado[i].kind,listado[i].duration[0],listado[i].duration[1],listado[i].autor);
        printf("-------------------------------\n");
    }
    fclose(archivo);
    free(listado);
    return listado;
}
