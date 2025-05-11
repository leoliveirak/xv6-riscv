#include "kernel/types.h"
#include "user/user.h"

int fib(int n) {
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

void main() {
    volatile int result;
    result = fib(42); // Valor alto para consumir bastante CPU
    // Evita otimização — não imprimimos, apenas armazenamos
} 
