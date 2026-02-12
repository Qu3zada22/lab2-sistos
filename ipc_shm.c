#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main() {

    const char *nombre = "/mi_memoria";
    const int TAM = 4096;

    int fd = shm_open(nombre, O_CREAT | O_RDWR, 0666);
    ftruncate(fd, TAM);

    char *ptr = mmap(0, TAM, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    pid_t pid = fork();

    if (pid == 0) {
        sleep(1);
        printf("Hijo lee: %s\n", ptr);
    } else {
        strcpy(ptr, "Hola desde memoria compartida!");
        wait(NULL);
        shm_unlink(nombre);
    }

    return 0;
}
