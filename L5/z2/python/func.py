from math import cos
def func(x):
    return x*x - 2*x

def halfcos(x):
    return cos(x/2)

def findzero(f, a, b, eps):
    c = (a + b) / 2
    prev = 0
    while b - a > eps:
        if f(c) * f(a) < 0:
            b = c
        else:
            a = c
        c = (a + b) / 2
    return c


def main():
    print(findzero(halfcos, 2, 4, 10**(-8)))

if __name__ == "__main__":
    main()
