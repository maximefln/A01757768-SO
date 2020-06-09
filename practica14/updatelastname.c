#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

typedef struct s 
{
    unsigned char id;
    unsigned char semester;
    char firstName[20];
    char lastName[20];
} Student;

int main(int argn, char **argv) {
    int id = atoi(argv[1]);
    int src;

    src = open("class.bin",O_RDWR);

    Student *myStudent1;
    myStudent1 = (Student *)malloc(sizeof(Student));
    
    lseek(src, id * sizeof(Student), SEEK_CUR);
    read(src, myStudent1, sizeof(Student));
    sprintf(myStudent1 -> lastName, "%s>%d", argv[2], id);
    for(int i = strlen(myStudent1 -> lastName); i < 20; i++) {
        myStudent1 -> lastName[i] = 0;
    }
    lseek(src, -sizeof(Student), SEEK_CUR);
    write(src, myStudent1, sizeof(Student));
    close(src);
    free(myStudent1);
    return 0;
}