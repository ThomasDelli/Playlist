#include "playlist.h"

int main()
{
    t_lista playlist;
    crear_listac(&playlist);

//    int vec[5] = {2,34,1,2,3};
//
//    for(int i = 0; i < 5; i++)
//    {
//        ponerSegundo(&playlist,&vec[i],sizeof(int));
//    }
//
//    map_listac(&playlist,mostrar_entero,NULL);

    ejecutar_programa(&playlist);

    vaciar_listac(&playlist);

    return 0;
}
