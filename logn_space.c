#include <stdio.h>

enum kval {K22 = 0, K11, K2, K1};

static void next(enum kval *v)
{
    switch (*v) {
        case K22:
        case K11:
            *v += 2;
            break;
        case K2:
        case K1:
            next(v + 1);
            *v = !(*v % 2) + 2 * (v[1] % 2);
            break;
    }
}

int main(void)
{
    unsigned long long n;
    enum kval stack[256] = {0};
    unsigned long long counts[2] = {1, 1};

    scanf("%llu", &n);
    for (unsigned long long i = 2; i < n; i++) {
        next(stack);
        counts[*stack % 2]++;
    }
    printf("%llu:%llu\n", counts[1], counts[0]);
}