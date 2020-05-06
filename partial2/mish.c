#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 80
#define MAX_NUM_ARGS 10
size_t string_parser(char *input, char *word_array[]) {
size_t n = 0;
while (*input) {
    while (isspace((unsigned char)*input))
        ++input;
        if (*input) {
            word_array[n++] = (char *)input;
            while (*input && !isspace((unsigned char)*input))
                ++input;
                *(input) = '\0';
                ++input;
            }
        }
    word_array[n] = NULL;
    return n;
}

int main(void) {
    char *args[MAX_NUM_ARGS + 1]; /* command line (of 80) has max of 5 arguments */
    char line[MAX_LINE + 1];
    int should_run = 1;

    int i;

    while (should_run) {
        printf("mish> ");
        fgets(line,MAX_LINE,stdin);
        line[strcspn(line, "\n")] = '\0';
        // Separamos la línea en palabras separadas por espacio
        // y las guardamos en args
        i = string_parser(line,args); // i contiene el número de argumentos
        printf("%d, %s %s\n", i, args[1],line); // Es solo para pruebas borrar cuando esté listo

        // if the command is exit, we end the while loop and exit the program (Q6)
         if (strcmp(args[0], "exit") == 0) {
                printf("I'll be back !\n");
                should_run = 0;
        } else {
            // we create a child process and pid = the pid of the child process (Q1)
            int pid = fork();
            // we make the father process wait for the child to end (Q4)
            waitpid(pid,0,0);
            if (!pid) {
                // child process part
                // we execute the commande with the arguments (Q2)
                int res = execvp(args[0], args);
                //if the program isn't found, we print an alert (Q3)
                if (res == -1){
                    printf("Programa no encontrado\n");
                }
            }
        }

        fflush(stdout);
        fflush(stdin);
        line[0] = '\0';
    }

    return 0;
}
