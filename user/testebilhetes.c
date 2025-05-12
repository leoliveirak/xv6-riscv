#include "kernel/types.h"
#include "user/user.h"

int main() {
  int pid;

  for (int i = 0; i < 3; i++) {
    pid = fork_com_bilhete(6); // Prioridade alta
    if (pid == 0) {
      while(1) {
        sleep(10);
        printf("Processo A (PID %d, bilhete 6) esta rodando\n", getpid());
        sleep(10);
      }
    }
  }

  for (int i = 0; i < 3; i++) {
    pid = fork_com_bilhete(1); // Prioridade mínima
    if (pid == 0) {
      while(1) {
        sleep(10);
        printf("Processo B (PID %d, bilhete 1) esta rodando\n", getpid());
        sleep(10);
      }
    }
  }

  // Processo pai espera
  wait(0);
  exit(0);
}
