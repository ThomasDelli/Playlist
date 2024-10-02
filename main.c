#include "playlist.h"

int main()
{
    char usuario[MAX_USER];
    t_lista library;
    crear_lista(&library);

    ///int vec[5] = {1,5,4,3,2},i;
    ///crear_listac(&library);

//    for(i =0;i < 5;i++){
//        ponerSegundo(&library,vec + i,sizeof(int));
//    }
//    map_listac(&library,mostrar_entero,NULL);
//    intercambia_nodos(&library,1,3);
//    printf("\n");
//    map_listac(&library,mostrar_entero,NULL);


    ingresar_usuario(usuario,MAX_USER);
    ejecutar_programa(&library,usuario);

    if(!lista_vacia(&library)){
        vaciar_lista(&library);
    }

<<<<<<< HEAD
    map_listac(&playlist,mostrar_entero,NULL);

    intercambia_nodos(&playlist,1,0);
    printf("\n");
    map_listac(&playlist,mostrar_entero,NULL);
*/

  ingresar_usuario(usuario,MAX_USER);
  ejecutar_programa(&playlist,usuario);

  if (!lista_vacia(&playlist))
  {
    vaciar_lista(&playlist);
  }
    
  return 0;
=======
    return 0;
>>>>>>> f1b2caa (refactor/intercanbiar_nodo mejorado.)
}
