#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/fcntl.h"
#include "user/user.h"

int main(int argc, char *argv[]) {
    
    const char *Archivo = argv[1];
    int nuevoModo = atoi(argv[2]);

    if (argc < 3) {
        printf("Uso: %s \n", argv[0]);
        exit(1);
    }

    
    int descriptorArchivo = open(Archivo, O_CREATE | O_WRONLY);
    if (descriptorArchivo < 0) {
        printf("Seprodujo un error al crear el archivo: %d\n", descriptorArchivo);
        exit(1);
    }

    int resultadoChmod = chmod(Archivo, nuevoModo); 
    if (resultadoChmod < 0) {
        printf("Error al cambiar el modo del archivo: %d\n", resultadoChmod);
        close(descriptorArchivo);
        exit(1);
    }

    printf("El archivo se creó y modificó correctamente\n");

    
    close(descriptorArchivo);

    exit(0);
}
