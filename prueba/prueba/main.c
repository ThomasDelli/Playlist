//#include <stdio.h>
//#include <windows.h> // Necesaria para mciSendString y otras funciones de Windows
//
//void reproducirCancion(const char* ruta) {
//    char comando[256];
//
//     Abrir el archivo de audio usando MCI
//    snprintf(comando, sizeof(comando), "open \"%s\" type mpegvideo alias miCancion", ruta);
//    mciSendString(comando, NULL, 0, NULL);
//
//     Reproducir el archivo de audio
//    mciSendString("play miCancion", NULL, 0, NULL);
//}
//
//void detenerCancion() {
//     Detener y cerrar el archivo de audio
//    mciSendString("stop miCancion", NULL, 0, NULL);
//    mciSendString("close miCancion", NULL, 0, NULL);
//}
//
//void pausarCancion() {
//     Pausar la canción actual
//    mciSendString("pause miCancion", NULL, 0, NULL);
//}
//
//void reanudarCancion() {
//     Reanudar la canción pausada
//    mciSendString("resume miCancion", NULL, 0, NULL);
//}
//
//void ajustarVolumen(int nivel) {
//    char comando[64];
//    snprintf(comando, sizeof(comando), "setaudio miCancion volume to %d", nivel);
//    mciSendString(comando, NULL, 0, NULL);
//}
//
//void ajustarVelocidad(int velocidad) {
//    char comando[64];
//    snprintf(comando, sizeof(comando), "set miCancion speed %d", velocidad);
//    mciSendString(comando, NULL, 0, NULL);
//}
//
//int main() {
//    const char* playlist[] = {
//        "C:\\Users\\admin\\Downloads\\Las Pastillas Del Abuelo - Viejo Karma!.wav",
//        "C:\\Users\\admin\\Downloads\\ytshorts.savetube.me_1727328465.0372734.wav",
//        "C:\\Users\\admin\\Downloads\\y2mate.com - Skay BeilinsonOda a la sin Nombre.mp3",
//        "C:\\Users\\admin\\Downloads\\y2mate.com - C Tangana Tiny Desk Home Concert_360P.mp4"
//    };
//
//    int numCanciones = sizeof(playlist) / sizeof(playlist[0]);
//    int opcion = -1;  // Opción del usuario
//    int cancionActual = 0;  // Índice de la canción que se está reproduciendo
//    int volumen = 500;  // Volumen inicial (50%)
//    int velocidad = 1000;  // Velocidad inicial (100%)
//
//    while (1) { // Bucle infinito para interactuar continuamente
//        printf("\nPlaylist:\n");
//        for (int i = 0; i < numCanciones; i++) {
//            printf("%d. %s\n", i + 1, playlist[i]);
//        }
//
//        printf("\nComandos:\n");
//        printf("1-%d: Seleccionar canción\n", numCanciones);
//        printf("0: Saltar a la siguiente canción\n");
//        printf("P: Pausar canción\n");
//        printf("R: Reanudar canción\n");
//        printf("S: Detener canción\n");
//        printf("+: Subir volumen\n");
//        printf("-: Bajar volumen\n");
//        printf(">+: Aumentar velocidad\n");
//        printf(">-: Disminuir velocidad\n");
//        printf("X: Salir\n");
//        printf("Elige una opción: ");
//
//        char input[10];
//        scanf("%s", input);
//
//        if (input[0] == 'X' || input[0] == 'x') {
//            printf("Saliendo...\n");
//            detenerCancion();
//            break;  // Salir del bucle y finalizar el programa
//        } else if (input[0] == '0') {
//             Saltar a la siguiente canción
//            detenerCancion();
//            cancionActual = (cancionActual + 1) % numCanciones;
//            printf("Saltando a la siguiente canción...\n");
//            printf("Reproduciendo: %s\n", playlist[cancionActual]);
//            reproducirCancion(playlist[cancionActual]);
//            ajustarVolumen(volumen);
//            ajustarVelocidad(velocidad);
//        } else if (input[0] >= '1' && input[0] <= '9') {
//             Reproducir la canción seleccionada (si el input es entre 1 y el número de canciones)
//            int seleccion = input[0] - '0';
//            if (seleccion >= 1 && seleccion <= numCanciones) {
//                detenerCancion();
//                cancionActual = seleccion - 1;
//                printf("Reproduciendo: %s\n", playlist[cancionActual]);
//                reproducirCancion(playlist[cancionActual]);
//                ajustarVolumen(volumen);
//                ajustarVelocidad(velocidad);
//            } else {
//                printf("Opción no válida. Inténtalo de nuevo.\n");
//            }
//        } else if (input[0] == 'P' || input[0] == 'p') {
//             Pausar la canción actual
//            printf("Pausando la canción...\n");
//            pausarCancion();
//        } else if (input[0] == 'R' || input[0] == 'r') {
//             Reanudar la canción actual
//            printf("Reanudando la canción...\n");
//            reanudarCancion();
//        } else if (input[0] == 'S' || input[0] == 's') {
//             Detener la canción actual
//            printf("Deteniendo la canción...\n");
//            detenerCancion();
//        } else if (input[0] == '+') {
//             Subir el volumen
//            if (volumen < 1000) {
//                volumen += 100;  // Subimos el volumen en 10%
//                if (volumen > 1000) volumen = 1000;  // El máximo es 1000
//                ajustarVolumen(volumen);
//                printf("Volumen: %d\n", volumen);
//            } else {
//                printf("Volumen ya está al máximo.\n");
//            }
//        } else if (input[0] == '-') {
//             Bajar el volumen
//            if (volumen > 0) {
//                volumen -= 100;  // Bajamos el volumen en 10%
//                if (volumen < 0) volumen = 0;  // El mínimo es 0 (silencio)
//                ajustarVolumen(volumen);
//                printf("Volumen: %d\n", volumen);
//            } else {
//                printf("El volumen ya está en silencio.\n");
//            }
//        } else if (input[0] == '>' && input[1] == '+') {
//             Aumentar la velocidad
//            if (velocidad < 2000) {
//                velocidad += 100;  // Aumentamos la velocidad
//                ajustarVelocidad(velocidad);
//                printf("Velocidad: %d\n", velocidad);
//            } else {
//                printf("La velocidad ya está al máximo.\n");
//            }
//        } else if (input[0] == '>' && input[1] == '-') {
//             Disminuir la velocidad
//            if (velocidad > 500) {
//                velocidad -= 100;  // Disminuimos la velocidad
//                ajustarVelocidad(velocidad);
//                printf("Velocidad: %d\n", velocidad);
//            } else {
//                printf("La velocidad ya está al mínimo.\n");
//            }
//        } else {
//            printf("Opción no válida. Inténtalo de nuevo.\n");
//        }
//    }
//
//    return 0;
//}

#include "playlist.h"
int main(){
    t_lista playlist;
    crear_listac(&playlist);

    ejecutar_programa(&playlist);

    vaciar_listac(&playlist);

return 0;
}
