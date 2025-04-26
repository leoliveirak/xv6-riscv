#include "types.h"
#include "riscv.h"       // Adicionar este include para o tipo pagetable_t
#include "defs.h"
#include "param.h"       // Pode ser necessário
#include "spinlock.h"    // Para acessar ticks, que está protegido por um spinlock

static uint64 a = 6364136223846793005ULL;
static uint64 c = 1;
static uint64 m = 18446744073709551615ULL;
static uint64 lcg_seed = 4937;
static int seeded = 0;

void srand_lcg(void) {
    lcg_seed = ticks;
    printf("%lu ", lcg_seed);
    seeded = 1;
}

uint64 random(void) {
    if (!seeded) {
        srand_lcg();
    }
    lcg_seed = (a * lcg_seed + c) % m;
    return lcg_seed;
}