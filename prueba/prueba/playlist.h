#ifndef PLAYLIST_H_INCLUDED
#define PLAYLIST_H_INCLUDED

#include "lista.h"
#include "lista_circular.h"
#define ERROR_ARCH 0

typedef struct {
        int minutos;
        int segundos;
}t_tiempo;

typedef struct {
            char nombre [100];
            char autor [50];
            t_tiempo duracion;
} t_cancion;

int ejecutar_programa(t_lista * p);
int abre_archivo_canciones(t_lista *c);
void mostrar_cancion(void* info);
int compara_canciones(void* a, void* b);
void menu();
int compara_nombre_canciones(void*,void*);
int compara_autor_canciones(void*,void*);
int compara_duracion_canciones(void*,void*);
void ordenar_lista_por_criterio (t_lista* c);
t_lista * crear_playlist(t_lista * p);
#endif // PLAYLIST_H_INCLUDED
