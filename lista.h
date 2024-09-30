#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HAY_MEMORIA 1
#define SIN_MEMORIA 0
#define minimo(a,b) ((a) <= (b) ? (a) : (b))

typedef struct sNodo
{
    void* info;
    unsigned tam_info;
    struct sNodo *sig;
} t_nodo;

typedef t_nodo * t_lista;


void crear_lista (t_lista *lista);
int agregar_en_lista_comienzo (t_lista *lista,void* dato,unsigned tam_dato);
int agregar_en_lista_final (t_lista *lista,void* dato,unsigned tam_dato);
int lista_vacia(const t_lista *lista);
int lista_llena (const t_lista *lista,unsigned);
int sacar_primero_de_lista(t_lista * lista, void*buffer,unsigned tam_buffer);
int sacar_ultimo_de_lista(t_lista * lista, void*buffer,unsigned tam_buffer);
void vaciar_lista (t_lista *lista);
int ver_primero_de_lista (const t_lista *lista, void*buffer, unsigned tam_buffer);
int ver_ultimo_de_lista (const t_lista *lista, void*buffer, unsigned tam_buffer);

void map_lista (t_lista *lista, void accion (void*,void*), void* param);
void mostrar_entero (void*, void*);
int eliminar_ocurrencias_clave (t_lista *lista, void* clave, int cmp (void*,void*));
int cmp_enteros (void*,void*);
int eliminar_ocurrencias_posicion (t_lista *lista,int posicion);
void ordena_lista (t_lista * lista, int cmp (void*,void*));
t_nodo ** buscar_menor (t_lista * lista,  int cmp (void*,void*));
void probando (t_lista *lista);
void ordena_lista_dos (t_lista *p,int x,int cmp(void*,void*));
void filtrar_mejores (t_lista *p,int x,int cmp(void*,void*));
int recorre_n_nodos(t_lista *p,void *d,unsigned tam_buffer,unsigned n);

#endif // LISTA_H_INCLUDED
