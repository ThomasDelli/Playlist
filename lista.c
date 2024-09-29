#include "lista.h"

void crear_lista (t_lista *lista)
{
    *lista = NULL;
}

int agregar_en_lista_comienzo (t_lista *lista,void*dato,unsigned tam_dato)
{

    t_nodo * nuevo = malloc (sizeof(t_nodo));

    if (!nuevo)
    {
        return SIN_MEMORIA;
    }

    nuevo->info = malloc (tam_dato);

    if (!nuevo->info)
    {
        free(nuevo);
        return SIN_MEMORIA;
    }

    memcpy(nuevo->info,dato,tam_dato);
    nuevo->tam_info=tam_dato;
    nuevo->sig = *lista;
    *lista = nuevo;
    return 1;
}

int lista_vacia(const t_lista *lista)
{

    return *lista == NULL;
}

int lista_llena (const t_lista *lista,unsigned tam_bytes)
{
    return HAY_MEMORIA;
}

int sacar_primero_de_lista(t_lista * lista, void*buffer,unsigned tam_buffer)
{
    t_nodo * elim;
    elim = *lista;
    if (elim == NULL)
    {
        return 0;
    }
    *lista = elim->sig;
    memcpy(buffer,elim->sig,minimo(tam_buffer,elim->tam_info));

    free(elim->info);
    free(elim);

    return 1;
}

void vaciar_lista (t_lista *lista)
{
    while (*lista)
    {
        t_nodo * aux = *lista;
        *lista = aux->sig;
        free (aux->info);
        free(aux);
    }

}

int ver_primero_de_lista (const t_lista *lista, void*buffer, unsigned tam_buffer)
{

    t_nodo *aux = *lista;

    if(*lista == NULL)
    {
        return 0;
    }

    memcpy(buffer, aux->info,minimo(tam_buffer,aux->tam_info));


    return 1;
}

int agregar_en_lista_final (t_lista *lista,void* dato,unsigned tam_dato)
{
    t_nodo *nue =(t_nodo*) malloc (sizeof(t_nodo));
    if(!nue)
    {
        return SIN_MEMORIA;
    }
    nue->info = malloc (tam_dato);
    if(!nue->info)
    {
        free(nue);
        return SIN_MEMORIA;
    }

    while (*lista)
    {
        lista = &(*lista)->sig;
    }

    memcpy(nue->info,dato,tam_dato);
    *lista = nue;
    nue->sig = NULL;
    nue->tam_info = tam_dato;

    return 1;
}

int sacar_ultimo_de_lista(t_lista * lista, void*buffer,unsigned tam_buffer)
{

    if(*lista == NULL)
    {
        return 0;
    }

    while ((*lista)->sig)
    {
        lista = &(*lista)->sig;
    }

    memcpy(buffer,(*lista)->info,minimo(tam_buffer,(*lista)->tam_info));

    free((*lista)->info);
    free(*lista);

    *lista = NULL;


    return 1;
}

int ver_ultimo_de_lista (const t_lista *lista, void*buffer, unsigned tam_buffer)
{
    if (*lista == NULL)
    {
        return 0;
    }
    while ((*lista)->sig)
    {
        lista = &(*lista)->sig;
    }

    memcpy(buffer, (*lista)->info,minimo(tam_buffer,(*lista)->tam_info));

    return 1;
}

////////////////////////////////////////////////////////////////////////////////////////7


void map_lista (t_lista *lista, void accion (void*,void*), void* param)
{

    while (*lista)
    {
        accion ((*lista)->info, param);
        lista = &(*lista)->sig;

    }

//    while(*lista)
//    {
//        accion((*lista)->info, NULL);
//        lista = &(*lista)->sig;
//    }
}

void mostrar_entero (void*a, void*b)
{
    printf("%d ",*(int*)a);
}



int eliminar_ocurrencias_clave (t_lista *lista, void* clave, int cmp (void*,void*))
{
    t_nodo * aux;

    while (*lista)   //Veo lista completa para analiar todas las posibles ocurrencias
    {

        if(cmp((*lista)->info,clave) == 0)  //Si encuentra ocurrencia eliminar nodo
        {
            aux = *lista;
            *lista = aux->sig;
            free(aux->info);
            free(aux);
        }
        else
        {
            lista = &(*lista)->sig;
        }

    }

    return 1;
}

int eliminar_ocurrencias_posicion (t_lista *lista, int posicion)
{
    int cont = 1;
    t_nodo * elim;

    while (*lista)
    {
        if (cont == posicion)
        {
            elim = *lista;
            *lista = elim->sig;
            free(elim->info);
            free(elim);
            return 1;
        }
        cont++;
        lista = &(*lista)->sig;
    }


    return 0;
}



void ordena_lista (t_lista * p, int cmp (void*,void*))
{

    t_nodo ** menor = p;
    t_nodo * aux;
    while (*p)
    {
        menor = buscar_menor (p,cmp);
        if (*menor != *p)
        {
            aux = *menor;
            *menor = aux->sig;
            aux->sig = *p;
            *p= aux;

        }

        p = &(*p)->sig;
    }

}

t_nodo ** buscar_menor (t_lista * p,  int cmp (void*,void*))
{
    t_nodo ** menor = (t_nodo**)p;

    while (*p)
    {
        if(cmp((*menor)->info,(*p)->info) > 0)
        {
            menor = (t_nodo**)p;
        }
        p = &(*p)->sig;
    }
    return menor;
}

void probando (t_lista *lista)
{
    t_nodo ** aux = (t_nodo**)lista;
    printf ("direccion de lista funcion: %p\n",*lista);
    printf ("direccion de lista funcion: %p\n",&lista);
    printf ("direccion de lista funcion: %p\n", lista);
    printf ("direccion de lista funcion: %p\n", aux);
    printf ("%d\n",*(int*)(*aux)->info);
    printf ("%d\n",*(int*)(*lista)->info);
}

void ordena_lista_dos (t_lista *p,int x,int cmp(void*,void*))
{

    t_nodo** proximo =  &(*p)->sig;
    t_nodo *aux;

    while (*p)  //1 ciclo para todo el manejo completo
    {

        //1 ciclo x nodo
        while((*proximo) !=NULL)
        {

            if (cmp((*p)->info,(*proximo)->info) > 0)
            {

                aux = *proximo;
                *proximo = aux->sig;
                aux->sig = *p;
                *p= aux;


            }

            else
            {
                proximo = &(*proximo)->sig;
            }

        }
        proximo = &(*p)->sig->sig;
        p = &(*p)->sig;
    }

}

void filtrar_mejores (t_lista *p,int x,int cmp(void*,void*))
{
    int i;
    t_nodo * aux;
    ordena_lista(p,cmp);

    for (i=0; i < x; i++)
    {

        p = &(*p)->sig;
    }

    while (*p)
    {
        aux= *p;
        *p = aux->sig;
        free (aux->info);
        free(aux);
    }


}

int cmp_enteros (void*a,void*b)
{
    int *pa = (int*)a;
    int *pb = (int*)b;
    return *pb-*pa;
}

int recorre_n_nodos(t_lista *p,void *d,unsigned tam_buffer,unsigned n)
{
    int i;
    if(*p == NULL) return 0;

    i = 0;
    while(*p && i < n )
    {
        p = &(*p)->sig;
        i++;
    }

    if( i == n)
    {
        memcpy(d,(*p)->info,minimo(tam_buffer,(*p)->tam_info));

        return 1;
    }

    return 0;
}
