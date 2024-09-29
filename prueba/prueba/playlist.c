#include "playlist.h"

int ejecutar_programa(t_lista * p)
{

    int opcion = 1;
    t_lista lista_canciones;
    t_lista  playlist;
    crear_lista(&lista_canciones);

    abre_archivo_canciones(&lista_canciones);
    ordena_lista(&lista_canciones,compara_canciones);

    while(opcion != -1)
    {

        menu();
        printf("Ingrese opcion -> ");
        scanf("%d",&opcion);
        puts("");
        switch(opcion)
        {
        case 1:
            map_lista(&lista_canciones,mostrar_cancion);
            break;
        case 2:
            ordenar_lista_por_criterio (&lista_canciones);
            break;
        case 3:
              system("cls");
             map_lista(&lista_canciones,mostrar_cancion);
            crear_playlist(&playlist);

            break;
        case -1:
            break;
        default:
            puts("Opcion invalida");
        }
         system("pause");
    }
    vaciar_lista(&lista_canciones);
    if(!lista_vacia(&playlist)){
    vaciar_listac(&playlist);
    }
    return 1;
}

int abre_archivo_canciones(t_lista * lista_canciones)
{
    t_cancion cancion;
    char linea[200];
    FILE *pf;
    pf = fopen("songs.txt","rt");
    if(!pf)
    {
        return ERROR_ARCH;
    }
    while(fgets(linea,sizeof(linea),pf))
    {
        sscanf(linea,"%[^;];%[^;];%d;%d",cancion.autor,cancion.nombre,&cancion.duracion.minutos,&cancion.duracion.segundos);
        agregar_en_lista_final(lista_canciones,&cancion,sizeof(t_cancion));
    }

    fclose(pf);
    return 1;
}

void mostrar_cancion(void* info)
{


    t_cancion*c = (t_cancion*)info;
    printf ("%-30s%-50s%d:%d\n",c->autor,c->nombre,c->duracion.minutos,c->duracion.segundos);

}

int compara_canciones(void* a, void* b)
{
    t_cancion* cancion1 = (t_cancion*)a;
    t_cancion* cancion2 = (t_cancion*)b;

    // 1. Comparar por autor
    int resultado = strcmp(cancion1->autor, cancion2->autor);
    if (resultado != 0)
    {
        return resultado; // Si los autores son diferentes, devuelve el resultado
    }

    // 2. Si los autores son iguales, comparar por nombre
    resultado = strcmp(cancion1->nombre, cancion2->nombre);
    if (resultado != 0)
    {
        return resultado; // Si los nombres son diferentes, devuelve el resultado
    }

    // 3. Si los nombres también son iguales, comparar por duración
    if (cancion1->duracion.minutos != cancion2->duracion.minutos)
    {
        return cancion1->duracion.minutos - cancion2->duracion.minutos; // Comparar minutos
    }
    return cancion1->duracion.segundos - cancion2->duracion.segundos; // Comparar segundos si los minutos son iguales
}

int compara_nombre_canciones(void*a,void*b)
{
    t_cancion* cancion1 = (t_cancion*)a;
    t_cancion* cancion2 = (t_cancion*)b;
    return strcmp(cancion1->nombre,cancion2->nombre);
}

int compara_autor_canciones(void*a,void*b)
{
    t_cancion* cancion1 = (t_cancion*)a;
    t_cancion* cancion2 = (t_cancion*)b;
    return strcmp(cancion1->autor,cancion2->autor);
}

int compara_duracion_canciones(void* a, void* b) {
    t_cancion* cancion1 = (t_cancion*)a;
    t_cancion* cancion2 = (t_cancion*)b;

    // Comparar por minutos primero
    if (cancion1->duracion.minutos != cancion2->duracion.minutos) {
        return cancion1->duracion.minutos - cancion2->duracion.minutos;
    }

    // Comparar por segundos si los minutos son iguales
    return cancion1->duracion.segundos - cancion2->duracion.segundos;

}

void menu()
{
    puts("\n------------------------------SPOTIUNLAM--------------------");

    puts("1) Ver lista de canciones.");
    puts("2) Cambiar orden de canciones.");
    puts("3) Crear playlist");
    puts("-1) Salir.");
}

void ordenar_lista_por_criterio (t_lista *c)
{
    int opcion;
    printf ("Ordenar por:\n1)Autor\n2)Nombre\n3)Duracion\n-> ");
    scanf("%d",&opcion);
    switch(opcion)
    {
    case 1:
        ordena_lista(c,compara_autor_canciones);
        break;
    case 2:
        ordena_lista(c,compara_nombre_canciones);
        break;
    case 3:
        ordena_lista(c,compara_duracion_canciones);
        break;
    default:
        puts("Opcion invalida");
    }


}

int crear_playlist(t_lista * p){
crear_listac(p);

puts("\nElige numero de cancion para agregar a la playlist ->");


system("pause");

return 1;
}
