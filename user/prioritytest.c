// user/prioritytest.c
#include "kernel/types.h"
#include "user/user.h"
//#include "stat.h"

#define NUM_CLASSES 4
//int nbilhetes[] = {6, 3, 2, 1};
int nbilhetes[] = {1, 2, 3, 6};

void work(int id, int iterations) {
    //printf("Process %d (PID %d) started\n", id, getpid());
    int i, j;
    for (i = 0; i < iterations; i++) {
        for (j = 0; j < 10000; j++); // Simula trabalho
        if ((i % 100) == 0) {
            //printf("Process %d (Priority Class %d, PID %d): Iteration %d\n", id, id, getpid(), i);
        }
    }
    printf("Process %d finished (PID %d)\n", id, getpid());
    exit(0);
}

int main(int argc, char *argv[]) {
    int pids[NUM_CLASSES];
    int iterations = 2000;

    //printf("Starting priority test with multiple processes using a loop...\n");

    for (int i = 0; i < NUM_CLASSES; i++) {
        pids[i] = fork_com_bilhete(nbilhetes[i]); // Passa o índice da classe como prioridade
        if (pids[i] == 0) {
            work(i, iterations); // Processo filho executa o trabalho
        } else if (pids[i] > 0) {
            printf("Created process %d (Priority Class %d, PID %d) with %d tickets\n",
                   i, i, pids[i], nbilhetes[i]);
        } else {
            //printf("Error forking process %d\n", i);
        }
    }

    // Espera por todos os processos filhos terminarem
    for (int i = 0; i < NUM_CLASSES; i++) {
        int waited_pid = wait(0);
        printf("Waited for PID %d (Class %d)\n", waited_pid, i);
    }

    printf("All processes finished.\n");
    exit(0);
}