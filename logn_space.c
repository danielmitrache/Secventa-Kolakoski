#include <stdio.h>
#define NMAX 100

enum kval {K22 = 0, K11 = 1, K2 = 2, K1 = 3};

static void next(enum kval *v)
{
    if (*v == K22 || *v == K11) {
        *v += 2;
    }
    else {
        next(v + 1);
        *v = !(*v % 2) + 2 * (v[1] % 2);
    }
}

int main(void)
{
    enum kval stack[256] = {0};
    printf("1 2 ");
    for (unsigned long long i = 2; i < NMAX; i++) {
        next(stack);
        printf("%d ", 2 - *stack % 2);
    }
}