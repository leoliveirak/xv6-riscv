#include "kernel/types.h"
#include "user/user.h"

#define N 4

int child[N];
int nbilhetes[] = {1, 2, 3, 6};
void waste_time(){
  volatile unsigned long long i;
  printf("start\n");
  for (i = 0; i < 3000000000ULL; ++i);
  printf("stop\n");
}

int
main(int argc, char *argv[])
{
int n, pid;
for(n=0; n<N; n++){
   pid = fork_com_bilhete(nbilhetes[n]);
   if(pid == 0) {
     waste_time();
     exit(0);
   }
   else child[n] = pid;
}

for(n=0; n<N; n++){
   pid = wait(0);
   printf("Child pid = %d finished!\n", pid);
}
return 0;

}