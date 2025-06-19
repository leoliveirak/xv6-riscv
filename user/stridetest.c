#include "kernel/types.h"
#include "user/user.h"

// ALTERAÇÃO 1: A função de trabalho agora é finita
// Simula uma carga de trabalho fixa para que possamos ver quem termina primeiro.
void fazer_trabalho(const char *name) {
    volatile long i;
    // Este loop é a "carga de trabalho". Todos os processos executam o mesmo número de iterações.
    for (i = 0; i < 3000000000ULL; i++) {
        if ((i % 500000000) == 0) {
            // Mensagem opcional para ver o progresso durante a execução
            fprintf(2, "Processo %s está trabalhando...\n", name);
        }
    }
    fprintf(2, "Processo %s TERMINPU...\n", name);

}

int
main(int argc, char *argv[])
{
    int pids[3];
    int tickets[] = {100, 50, 250};
    char *names[] = {"A", "B", "C"};

    fprintf(1, "Iniciando teste de Stride Scheduling com trabalho finito...\n");
    fprintf(1, "A(100), B(50), C(250)\n");
    fprintf(1, "Expectativa: C terminará primeiro, depois A, e por último B.\n\n");

    for (int i = 0; i < 3; i++) {
        pids[i] = fork_com_bilhete(tickets[i]);
        if (pids[i] == 0) { // Processo filho
            // ALTERAÇÃO 2: Lógica do filho
            fprintf(1, "Filho %s (PID %d) iniciado com %d bilhetes.\n", names[i], getpid(), tickets[i]);
            
            fazer_trabalho(names[i]); // Executa a carga de trabalho finita

            // Imprime a mensagem de conclusão formatada
            fprintf(1, "PROCESSO %s (PID %d) TERMINEI com %d bilhetes\n", names[i], getpid(), tickets[i]);
            
            exit(0); // Termina o processo filho
        } else if (pids[i] < 0) {
            fprintf(2, "Erro: fork_com_bilhetes falhou\n");
            exit(1);
        }
    }

    // ALTERAÇÃO 3: Lógica do pai
    // O pai agora espera que todos os 3 filhos terminem.
    fprintf(1, "\nPai esperando todos os filhos terminarem...\n");
    for (int i = 0; i < 3; i++) {
        wait(0); // wait(0) espera por qualquer processo filho terminar.
    }
    
    fprintf(1, "\nTodos os filhos terminaram. Teste concluído.\n");

    exit(0);
}