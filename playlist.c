#include "playlist.h"

int ejecutar_programa(t_lista *lista_canciones,char *usuario)
{
    t_lista playlist;
    int opcion = 1,pos, nroLista = 0;

    abre_archivo_canciones(lista_canciones);
    ordena_lista(lista_canciones, compara_canciones);

    while (opcion != -1)
    {
        pos = 1;
        menu(usuario);
        printf("Ingrese opcion -> ");
        scanf("%d", &opcion);
        puts("");
        switch (opcion)
        {
        case 1:
            map_lista(lista_canciones, mostrar_cancion_numerada,&pos);
            break;
        case 2:
            ordenar_lista_por_criterio(lista_canciones);
            break;
        case 3:
            system("cls");
            crear_playlist(&playlist,lista_canciones,++nroLista,usuario);
            break;
        case -1:
            break;
        default:
            puts("Opcion invalida");
        }


    }


    return 1;
}

int abre_archivo_canciones(t_lista *lista_canciones)
{
    t_cancion cancion;
    char linea[200];
    FILE *pf;
    pf = fopen("songs.txt", "rt");
    if (!pf)
    {
        return ERROR_ARCH;
    }
    while (fgets(linea, sizeof(linea), pf))
    {
        sscanf(linea, "%[^;];%[^;];%d;%d", cancion.autor, cancion.nombre, &cancion.duracion.minutos, &cancion.duracion.segundos);
        agregar_en_lista_final(lista_canciones, &cancion, sizeof(t_cancion));
    }

    fclose(pf);
    return 1;
}

void mostrar_cancion_numerada(void *info,void *cont)
{
    unsigned *num = (unsigned *) cont;
    t_cancion *c = (t_cancion *)info;
    printf("%3d - %-30s%-50s%d:%02d\n",*num, c->autor, c->nombre, c->duracion.minutos, c->duracion.segundos);

    (*num)++;

}

void mostrar_cancion(void *info)
{
    t_cancion *c = (t_cancion *)info;
    printf("%-30s%-50s%d:%02d\n", c->autor, c->nombre, c->duracion.minutos, c->duracion.segundos);
}

int compara_canciones(void *a, void *b)
{
    t_cancion *cancion1 = (t_cancion *)a;
    t_cancion *cancion2 = (t_cancion *)b;

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

    // 3. Si los nombres tambien son iguales, comparar por duracion
    if (cancion1->duracion.minutos != cancion2->duracion.minutos)
    {
        return cancion1->duracion.minutos - cancion2->duracion.minutos; // Comparar minutos
    }
    return cancion1->duracion.segundos - cancion2->duracion.segundos; // Comparar segundos si los minutos son iguales
}

int compara_nombre_canciones(void *a, void *b)
{
    t_cancion *cancion1 = (t_cancion *)a;
    t_cancion *cancion2 = (t_cancion *)b;
    return strcmp(cancion1->nombre, cancion2->nombre);
}

int compara_autor_canciones(void *a, void *b)
{
    t_cancion *cancion1 = (t_cancion *)a;
    t_cancion *cancion2 = (t_cancion *)b;
    return strcmp(cancion1->autor, cancion2->autor);
}

int compara_duracion_canciones(void *a, void *b)
{
    t_cancion *cancion1 = (t_cancion *)a;
    t_cancion *cancion2 = (t_cancion *)b;

    // Comparar por minutos primero
    if (cancion1->duracion.minutos != cancion2->duracion.minutos)
    {
        return cancion1->duracion.minutos - cancion2->duracion.minutos;
    }

    // Comparar por segundos si los minutos son iguales
    return cancion1->duracion.segundos - cancion2->duracion.segundos;
}

void menu(char *usuario)
{
    printf("\n------------------------------SPOTIUNLAM-----------------Usuario logeado:%s\n\n",usuario);

    puts("1) Ver lista de canciones.");
    puts("2) Cambiar orden de canciones.");
    puts("3) Crear playlist");
    puts("-1) Salir.");
    puts("------------------------------------------------------------------------------------");
}

void ordenar_lista_por_criterio(t_lista *c)
{
    int opcion;
    printf("Ordenar por:\n1)Autor\n2)Nombre\n3)Duracion\n-> ");
    scanf("%d", &opcion);
    switch (opcion)
    {
    case 1:
        ordena_lista(c, compara_autor_canciones);
        break;
    case 2:
        ordena_lista(c, compara_nombre_canciones);
        break;
    case 3:
        ordena_lista(c, compara_duracion_canciones);
        break;
    default:
        puts("Opcion invalida");
    }
}

int crear_playlist(t_lista *play,t_lista *lib,int nroLista,char* usuario)
{
    t_cancion seleccionada;
    int pos,cont,opcion = 1,cant_canciones=0;
    crear_listac(play);

    while(opcion != -1)
    {
        pos = 1;
        cont = 1;
        map_lista(lib, mostrar_cancion_numerada,&cont);
        do
        {
            puts("\nElige numero de cancion para agregar a la playlist ->");
            fflush(stdin);
            scanf("%d",&pos);
            if(pos < 1 || pos > cont-1) puts("\nOpcion Invalida.");
        }
        while(pos  < 1 || pos > cont-1);

        recorre_n_nodos(lib,&seleccionada,sizeof(t_cancion),pos - 1);
        puts("\nSeleccionaste: ");
        mostrar_cancion(&seleccionada);


        do
        {
            puts("\n\n1) Guardar en playlist.\n2) Mostrar Playlist.\n3) Vaciar playlist.\n4) Agregar nueva cancion.\n5) Eliminar una cancion.\n6) Cambiar orden cancion\n-1) Salir.\n\nElige una opcion ->");
            fflush(stdin);
            scanf("%d",&opcion);
            system("cls");

            switch(opcion)
            {
            case 1:
                ponerSegundo(play,&seleccionada,sizeof(t_cancion));
                puts("Se agrego la cancion a la playlist");
                cant_canciones++;
                break;
            case 2:
                pos = 1;
                if(!listac_vacia(play))
                {
                    printf("Playlist creada por %s\n",usuario);
                    map_listac(play,mostrar_cancion_numerada,&pos);
                }
                else
                    puts("La playlist esta vacia");
                break;
            case 3:
                vaciar_listac(play);
                puts("Se vacio la playlist");
                break;
            case 4:

                break;
            case 5:
                if(!listac_vacia(play))
                    eliminar_cancion(play,&cant_canciones);
                else
                    puts("La playlist esta vacia");
                break;
            case 6:
                if(!listac_vacia(play) && !solo_un_elemento_listac (play))
                {
                    cambiar_orden_playlist(play);
                }
                else
                    puts("La playlist esta vacia o solo tiene una cancion agregada");

                break;
            case -1:
                break;
            default:
                puts("Opcion invalida");
            }
        }
        while((opcion != -1) && (opcion != 4));

    }

    if(!*play)
    {
        puts("NO SE CREO NINGUNA PLAYLIST\n");
        return 0;
    }
    else
    {
        convertir_playlist_a_texto(play, nroLista);
    }

    if (!lista_vacia(play))
    {
        vaciar_listac(play);
    }

    return 1;
}


int convertir_playlist_a_texto(t_lista* play, int nroLista)
{
    char nombrePlaylist[20] = "PLAY";
    t_tiempo duracionTotal = {00,00};
    t_cancion cancion;

    FILE* pf = fopen(crear_nombre_playlist(nombrePlaylist, nroLista), "wt");
    if(!pf)
        return 0;///error de archivo


    fprintf(pf, "PLAYLIST %d\n\n",nroLista);
    while(sacar_primero_listac(play, &cancion, sizeof(t_cancion)))
    {
        fprintf(pf,"%-30s%-50s%d:%02d\n", cancion.autor, cancion.nombre, cancion.duracion.minutos, cancion.duracion.segundos);

        duracionTotal.segundos += cancion.duracion.segundos;
        if(duracionTotal.segundos >= 60)
        {
            duracionTotal.segundos -= 60;
            duracionTotal.minutos++;
            duracionTotal.minutos += cancion.duracion.minutos;
        }
        else
        {
            duracionTotal.minutos += cancion.duracion.minutos;
        }
    }
    fprintf(pf, "\nDURACION TOTAL  %d:%02d",duracionTotal.minutos,duracionTotal.segundos);


    fclose(pf);

    return 1;
}

char* crear_nombre_playlist(char* nomPlaylist, int nroLista)
{
    char extension[5] = ".txt";
    char num = nroLista + '0';
    char* aux = strrchr(nomPlaylist,'\0');

    *aux = num;
    aux++;

    strcat(aux, extension);

    return nomPlaylist;
}


int ingresar_usuario(char *user, int longitud)
{
    printf("\t\t\t***************************************\n");
    printf("\t\t\t*        BIENVENIDO A SPOTIUNLAM      *\n");
    printf("\t\t\t***************************************\n\n");


    printf("Por favor, ingrese su nombre de usuario (max %d caracteres):\n\n", longitud);

    printf("+---------------------+\n");
    printf("|                     |\r");
    size_t len;
    fgets(user, longitud, stdin);

    // Eliminar el salto de línea '\n' agregado por fgets
    len = strlen(user);
    if (len > 0 && user[len - 1] == '\n')
    {
        user[len - 1] = '\0';
    }

    system("cls");


    return 1;
}

int eliminar_cancion(t_lista * play,int *cantidad)
{
    int pos, cant_canciones = 1;
    char op;
    t_cancion seleccionada;

    map_listac(play,mostrar_cancion_numerada,&cant_canciones);
    puts("\nElige cual opcion desea eliminar");
    do
    {
        scanf("%d",&pos);
        if(pos < 1 || pos > (*cantidad)) puts("Opcion invalida");
    }
    while(pos < 1 || pos > (*cantidad));

    recorre_n_nodos(play,&seleccionada,sizeof(t_cancion),pos-1);
    puts("\nSeleccionaste:");
    mostrar_cancion(&seleccionada);
    printf("\nDesea eliminar la cancion(Y/N)?: ");

    do
    {
        fflush(stdin);
        scanf("%c",&op);
        if(!OPCION_VALIDA(op)) puts("Opcion invalida");
    }
    while(!OPCION_VALIDA(op));

    if (op == 'Y' || op == 'y')
    {
        elimina_n_nodo_playlist (play,&seleccionada,sizeof(t_cancion),pos);
        puts("Cancion eliminada con exito");
        (*cantidad)--;
    }

    return 1;
}

int elimina_n_nodo_playlist (t_lista *p,void*info,unsigned tam,int pos)
{

    int i =0;
    t_cancion buffer;

    while (i < pos-1)
    {

        p=&(*p)->sig;
        i++;
    }

    sacar_primero_listac(p,&buffer,sizeof(t_cancion));

    return 1;
}

int cambiar_orden_playlist(t_lista* play)
{
    t_cancion seleccionada;
    int opcion,cant_canciones =1,nuevo_orden;
    map_listac(play,mostrar_cancion_numerada,&cant_canciones);

    do
    {
        puts("Seleccione cual cancion desea cambiar el orden");
        scanf("%d",&opcion);
        if (opcion < 1 || opcion > cant_canciones-1) puts("Opcion invalida");
    }
    while (opcion < 1 || opcion > cant_canciones-1);

    recorre_n_nodos(play,&seleccionada,sizeof(t_cancion),opcion-1);
    puts("\nCancion seleccionada: ");
    mostrar_cancion(&seleccionada);
    puts("\nIngrese nuevo orden ->");

    do
    {
        scanf("%d",&nuevo_orden);
        if(nuevo_orden == opcion) puts("La cancion ya se encuentra en esa posicion");
        else if (nuevo_orden < 1 || nuevo_orden > cant_canciones - 1) puts ("Opcion invalida");

    }
    while((nuevo_orden < 1) || (nuevo_orden == opcion) || (nuevo_orden > cant_canciones-1));
    intercambia_nodos(play,opcion-1,nuevo_orden-1);

    return 1;
}
