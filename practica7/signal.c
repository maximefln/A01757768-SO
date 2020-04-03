#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void processSignal(int s){
    printf("Recibi signal %d\n", s);
}

void killsignal(int s){
    printf("Imposible kill con ctrl + c");
}

int main(){
    signal(10, processSignal);
    signal(15, killsignal);
    while(1){
        sleep(3);
        printf("Trabajando\n");
    }
    return 1;
}