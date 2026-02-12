#include <stdio.h>
#include <unistd.h>

int main() {

    pid_t pid = fork();

    if (pid == 0) {
        printf("Hijo terminado\n");
        return 0;
    } else {
        printf("Padre durmiendo 60 segundos...\n");
        sleep(60);
    }

    return 0;
}
