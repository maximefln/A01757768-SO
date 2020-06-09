#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct s 
{
    unsigned char id;
    unsigned char semester;
    char firstName[20];
    char lastName[20];
} Student;

int main() {
    int destination;
    destination = creat("class.bin",0600);

    for (int i = 0; i < 10; i++) {
        Student *myStudent1;
        myStudent1 = (Student *)malloc(sizeof(Student));
        myStudent1-> id = i;
        myStudent1 -> semester = 2;
        sprintf(myStudent1 -> firstName,"%s", "Miguel");
        sprintf(myStudent1 -> lastName, "%s>%d", "Perez", i);
        int n = write(destination, myStudent1, sizeof(Student));
        free(myStudent1);
    }
    close(destination);
    return 0;
}