#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    printf("cuantas veces\n");
    int pid = fork();
    if (pid==0) printf("Soy el hijo\n");
    else printf("Soy el padre\n");
    fork();
    fork();
    printf("cuantas veces otra vez\n");
}