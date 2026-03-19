import sys
import packages.primenumbers as pp

def main():
    if len(sys.argv) != 2:
        print("Zła liczba argumentów")
        return
    n = int(sys.argv[1])
    if n < 0:
        print("Liczby nie mogą być mniejsze od 0")
        return
    if n < 2:
        print("0")
        return
    s = []
    pp.create_sieve(s, n)
    pp.compute_sieve(s)
    c = pp.count_primes(s)
    print(c)

if __name__ == "__main__":
    main()
