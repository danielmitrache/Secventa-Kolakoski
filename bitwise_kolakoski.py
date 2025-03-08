NMAX = 20

def Kolakoski():
    x = y = -1
    for i in range(NMAX):
        print([2,1][x&1], end=' ')
        f = y & ~(y + 1)
        x ^= f
        y = (y + 1) | (f & (x>>1))

Kolakoski()