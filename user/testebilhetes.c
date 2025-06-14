#include "kernel/types.h"
#include "user/user.h"

int main() {
  int pid;
  int passos = 6;
  int passo = 1;

  for (int i = 0; i < 3; i++) {
    pid = fork_com_bilhete(6); // Prioridade alta
    if (pid == 0) {
      while(1) {
        sleep(10);
        passos += passos;
        printf("Processo A (PID %d, passos %d 6) esta rodando\n", getpid(), passos);
        sleep(10);
      } 
    }
  }

  for (int i = 0; i < 3; i++) {
    pid = fork_com_bilhete(1); // Prioridade mínima
    if (pid == 0) {
      while(1) {
        sleep(10);
        passo += passo;
        printf("Processo B (PID %d, passos %d 1) esta rodando\n", getpid(), passo);
        sleep(10);
      }
    }
  }

  // Processo pai espera
  wait(0);
  exit(0);
}
