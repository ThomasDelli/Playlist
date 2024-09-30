#include "playlist.h"

int main()
{
    char usuario[MAX_USER];
    t_lista playlist;
    crear_lista(&playlist);

    ingresar_usuario(usuario,MAX_USER);
    ejecutar_programa(&playlist,usuario);

    if (!lista_vacia(&playlist))
    {
        vaciar_lista(&playlist);
    }
    return 0;
}
