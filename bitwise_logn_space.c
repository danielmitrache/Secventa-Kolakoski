#include <stdio.h>
#define NMAX 100

int Kolakoski() {
    int x = -1, y = -1, k[2] = {2, 1}, f;
    for (unsigned long long i = 2; i < NMAX; i++) {
        printf("%d ", k[x & 1]);
        f = y & ~(y + 1);
        x ^= f;
        y = (y + 1) | (f & (x >> 1));
    }
}

int main() {
    Kolakoski();
    return 0;
}