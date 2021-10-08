#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"


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

//------------------------------------------------------

//Entrada: No recibe
//Salida: Un arreglo de estructuras del tipo song
//Función: Lee el archivo listado.in y lo ordena de menor a mayor (indice) por genero musical

song * leerListado(){
    song * listado = (song*)malloc(sizeof(song)*0);
    FILE *archivo = fopen("listado.in", "r");
    song aux;
    char strAux[150];
    int cantidad;
    cantidad = atoi(fgets(strAux,150,archivo));
    for(int i = 0; i < cantidad;i++){
        fgets(strAux,150,archivo);
        aux.name = strtok(strAux," ");
        aux.kind = atoi(strtok(NULL," "));
        aux.duration[0] = atoi(strtok(NULL,":"));
        aux.duration[1] = atoi(strtok(NULL," "));
        aux.autor = strtok(NULL,"\n");
        
    }
    return listado;
}
