#ifndef LISTA_CIRCULAR_H_INCLUDED
#define LISTA_CIRCULAR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"
#define SIN_MEMORIA 0

void crear_listac (t_lista *p);
void vaciar_listac (t_lista *p);
int listac_vacia (t_lista *p);
int ponerSegundo(t_lista *p, void*dato, unsigned tamDato);
int poner_listac_inicio (t_lista *,void*info,unsigned tam);
int poner_listac_final (t_lista *,void*info,unsigned tam);
int map_listac (t_lista *p, void accion (void*,void*),void *param);
void mostrar_numeros(void*info);
#endif // LISTA_CIRCULAR_H_INCLUDED
