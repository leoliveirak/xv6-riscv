#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[]) {
  int ticks;

  printf("Iniciando teste de uptime...\n");

  ticks = uptime();

  printf("Número de ticks desde o boot: %d\n", ticks);

  exit(0);
}