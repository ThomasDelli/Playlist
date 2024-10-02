#include "playlist.h"

int main()
{
    char usuario[MAX_USER];
    t_lista playlist;
    //int vec[5] = {1,5,4,3,2},i;
    crear_lista(&playlist);
    //crear_listac(&playlist);

    /*for(i =0;i < 5;i++){
        ponerSegundo(&playlist,vec + i,sizeof(int));
    }

    map_listac(&playlist,mostrar_entero,NULL);

    intercambia_nodos(&playlist,1,0);
    printf("\n");
    map_listac(&playlist,mostrar_entero,NULL);
*/

  ingresar_usuario(usuario,MAX_USER);
  ejecutar_programa(&playlist,usuario);

    return 0;
}
