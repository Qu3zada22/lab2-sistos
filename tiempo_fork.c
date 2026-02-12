#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

    clock_t inicio, fin;
    double tiempo;

    inicio = clock();

    for(int i = 0; i < 3; i++) {
        pid_t pid = fork();

        if(pid == 0) {
            for(long j = 0; j < 500000000; j++) {}
            return 0;
        }
    }

    for(int i = 0; i < 3; i++) {
        wait(NULL);
    }

    fin = clock();

    tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;

    printf("Tiempo con fork: %f segundos\n", tiempo);

    return 0;
}
