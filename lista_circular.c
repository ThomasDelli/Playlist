#include "lista_circular.h"

void crear_listac (t_lista *p)
{
    *p = NULL;
}

int poner_listac_inicio (t_lista *p,void*info,unsigned tam)
{
    t_nodo *pri = *p;
    t_nodo *aux = *p;
    t_nodo *nue = malloc (sizeof(t_nodo));

    if (!nue)
    {
        return SIN_MEMORIA;
    }
    nue->info = malloc (tam);
    if(!nue->info)
    {
    free (nue);
        return SIN_MEMORIA;
    }

    memcpy(nue->info,info,tam);
    nue->tam_info=tam;



    if(*p == NULL){
        nue->sig = nue;

    }
    else
    {
       while (aux->sig != pri){
        aux = aux->sig;
       }
       aux->sig = nue;
       nue->sig = pri;

    }

    *p = nue;

    return 1;
}
int poner_listac_final (t_lista *p,void*info,unsigned tam){

    t_nodo *pri = *p;
    t_nodo *nue = malloc (sizeof(t_nodo));

    if (!nue)
    {
        return SIN_MEMORIA;
    }
    nue->info = malloc (tam);
    if(!nue->info)
    {
    free (nue);
        return SIN_MEMORIA;
    }

    memcpy(nue->info,info,tam);
    nue->tam_info=tam;

     if(*p == NULL){
        nue->sig = nue;
        *p=nue;
    }
    else
    {
       while ((*p)->sig != pri){
        p = &(*p)->sig;
       }

       (*p)->sig = nue;
       nue->sig = pri;

    }

return 1;
}
int map_listac (t_lista *p, void accion (void*)){
int i =0;
if(*p == NULL){
    return 0;
}

while (i<20){
 accion((*p)->info);
 p = &(*p)->sig;
 i++;
}

return 1;
}

void mostrar_numeros(void*info){
int *num = (int*)info;
printf ("%d",*num);
}

void vaciar_listac(t_lista *p) {
    if (!*p) {
        return; // Si la lista está vacía, no hacemos nada
    }

    t_nodo *pri = *p;  // Guardamos el puntero al primer nodo
    t_nodo *sig = (*p)->sig;  // Iniciamos con el siguiente nodo del primero

    // Si hay más de un nodo en la lista, entramos en el ciclo
    while (sig != pri) {
        t_nodo *aux = sig->sig; // Guardamos el siguiente nodo
        free(sig->info);        // Liberamos la información del nodo actual
        free(sig);              // Liberamos el nodo actual
        sig = aux;             // Avanzamos al siguiente nodo
    }

    // Liberamos el nodo que apuntaba a sí mismo (el primer nodo que queda por liberar)
    free(pri->info);
    free(pri);

    *p = NULL;  // Marcamos la lista como vacía
}

int listac_vacia (t_lista *p){
return *p == NULL;
}
