#include "kernel/types.h"
#include "user/user.h"

int main(void) {
  int count[4] = {0, 0, 0, 0}; // contador para classes 0 a 3
  int total = 1000;

  printf("Testando sorteio de classes com random()\n");

  for(int i = 0; i < total; i++){
    int r = random() % 12;

    int classe;
    if(r < 6) classe = 0;
    else if(r < 6 + 3) classe = 1;
    else if(r < 6 + 3 + 2) classe = 2;
    else classe = 3;

    count[classe]++;
  }

  printf("Resultados após %d sorteios:\n", total);
  printf("Classe 0: %d vezes\n", count[0]);
  printf("Classe 1: %d vezes\n", count[1]);
  printf("Classe 2: %d vezes\n", count[2]);
  printf("Classe 3: %d vezes\n", count[3]);

  exit(0);
}
