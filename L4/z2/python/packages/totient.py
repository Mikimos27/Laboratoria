import math

def is_prime(n):
    if n <= 1:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    i = 3
    while i * i <= n:
        if n % i == 0:
            return False
        i = i + 1
    return True

def factor(on):

    n = on
    if(is_prime(n)):
        return set([n])
    s = set([])
    i = 2
    while i <= n:
        if n % i == 0 :
            if is_prime(i):
                s.add(i)
        i = i + 1

    
    return s


def totient(n):
    if n < 2:
        return 1
    if is_prime(n):
        return n - 1
    print(factor(n));
    s = factor(n)
    res = n
    for i in s:
        res = res - res // i

    return res

