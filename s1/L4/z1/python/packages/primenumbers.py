import math
def create_sieve(s, n):
    for _ in range(n + 1):
        s.append(True)

def compute_sieve(s):
    for i in range(2, len(s)):
        if s[i]:
            j = i + i
            while j < len(s):
                s[j] = False
                j = j + i

def sqrt_compute_sieve(s):
    for i in range(2, int(math.sqrt(len(s)))):
        if s[i]:
            j = i + i
            while j < len(s):
                s[j] = False
                j = j + i

def count_primes(s):
    c = 0
    for i in range(2, len(s)):
        if s[i]:
            c = c + 1
    return c

def PrimeNumbers(n):
    s = []
    create_sieve(s, n)
    compute_sieve(s)
    return count_primes(s)

def Prime(n):
    flag = False
    arr = []
    for i in range(0, n + 2):
        arr.append(0)
    arr[1] = 2
    arr[2] = 3
    licz = 5
    k = 2
    while k < n:
        flag = True
        for i in range(1, k + 1):
            if arr[i] * arr[i] > licz:
                break
            if licz % arr[i] == 0:
                flag = False
                break

        if flag:
            k = k + 1
            arr[k] = licz
        licz = licz + 2
    return arr[n]


def IsPrime(n):
    s = []
    create_sieve(s, n)
    sqrt_compute_sieve(s)
    return s[n]
