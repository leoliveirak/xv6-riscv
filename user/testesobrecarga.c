#include "kernel/types.h"
#include "user/user.h"

int main(void) {
  long long int interacoes = 1000000000; 
  double pi = 0.0;
  int sing = 1;

  for (long long int i = 0; i < interacoes; i++){
    pi += sing * (4.0 / (2.0 * i + 1.0));
    sing *= -sing;

    printf("Resultados após %d sorteios:\n", pi);
  }

  
  exit(0);
}
