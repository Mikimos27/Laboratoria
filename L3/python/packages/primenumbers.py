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

def count_primes(s):
    c = 0
    for i in range(2, len(s)):
        if s[i]:
            c = c + 1
    return c

