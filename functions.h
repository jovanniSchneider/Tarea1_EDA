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
    song temporal;
    strcpy(temporal.name,cancion1->name);
    strcpy(temporal.autor,cancion1->autor);
    temporal.duration[0] = cancion1->duration[0];
    temporal.duration[1] = cancion1->duration[1];
    temporal.kind = cancion1->kind;
    cancion1->duration[0] = cancion2->duration[0];
    cancion1->duration[1] = cancion2->duration[1];
    strcpy(cancion1->autor,cancion2->autor);
    strcpy(cancion1->name,cancion2->name);
    cancion2->duration[0] = temporal.duration[0];
    cancion2->duration[1] = temporal.duration[1];
    strcpy(cancion2->autor,temporal.autor);
    strcpy(cancion2->name,temporal.name);
}

int particiona(song * lista, int inicio, int fin){
    int izquierda = inicio;
    int derecha = fin;
    int temporal;
    int pivote = lista[(izquierda+derecha)/2].kind;
    printf("pivote: %d\n",pivote);
    printf("izquierda %d\n",izquierda);
    printf("derecha %d\n",derecha);
    printf("%d\n",lista[izquierda].kind);
    do
    {
        while (lista[izquierda].kind < pivote && izquierda<fin)
        {
            printf("Aqui voy\n");
            izquierda++;
        }
        while (lista[derecha].kind > pivote && derecha>inicio)
        {
            derecha--;
        }
        if (izquierda<=derecha)
        {
            swap(&lista[izquierda],&lista[derecha]);
        }
    } while (izquierda<=derecha);
    
}





song * quicksort(song * lista, int inicio, int fin){
    if (inicio<fin)
    {
            int pivote = particiona(lista,inicio,fin);
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
    quicksort(listado,0,cantidad-1);
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
