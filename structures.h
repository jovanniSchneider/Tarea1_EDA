typedef struct song
{
    int kind; //genero musical de la cancion
    char * name; //nombre de la cancion
    int duration[2]; //duracion de la cancion, posicion 0 minutos y posicion 1 segundos.
    char * autor; //autor de la cancion
}song;
