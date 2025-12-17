import sys
import packages.primenumbers as pp

def main():
    if len(sys.argv) != 3:
        print("Zła liczba argumentów")
        return
    n = int(sys.argv[2])
    s = sys.argv[1]
    if s == "pn":
        print(pp.PrimeNumbers(n))
    elif s == "pr":
        print(pp.Prime(n))
    elif s == "ip":
        print(pp.IsPrime(n))
    else:
        print("Zła komenda");


if __name__ == "__main__":
    main()
