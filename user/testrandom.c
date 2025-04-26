#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char *argv[]) {
    printf("Testando random()\n");

    for(int i = 0; i < 100; i++){
        uint64 r = random();
        r = r % 12;
        printf("%lu ", r);
    }

    exit(0);
}