#ifndef PLAYLIST_H_INCLUDED
#define PLAYLIST_H_INCLUDED

#include "lista.h"
#include "lista_circular.h"
#define ERROR_ARCH 0

typedef struct
{
    int minutos;
    int segundos;
} t_tiempo;

typedef struct
{
    char nombre [100];
    char autor [50];
    t_tiempo duracion;
} t_cancion;

int ejecutar_programa(t_lista * p,char*usuario);
int abre_archivo_canciones(t_lista *c);
void mostrar_cancion_numerada(void *info,void *cont);
void mostrar_cancion(void* info);
int compara_canciones(void* a, void* b);
void menu(char*);
int compara_nombre_canciones(void*,void*);
int compara_autor_canciones(void*,void*);
int compara_duracion_canciones(void*,void*);
void ordenar_lista_por_criterio (t_lista* c);
int crear_playlist(t_lista *play,t_lista *lib, int nroLista,char *usuario);
int ingresar_usuario (char *user, int longitud);
int convertir_playlist_a_texto(t_lista* play, int nroLista);
char* crear_nombre_playlist(char* nomPlaylist, int nroLista);

#endif // PLAYLIST_H_INCLUDED
