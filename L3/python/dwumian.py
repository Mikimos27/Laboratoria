import sys

def dwumian(n ,k):
    k = min(k, n - k)
    C = []
    for i in range(0, k + 2):
        C.append(0)
    C[0] = 1
    for i in range(0, n + 1):
        if i <= k:
            C[i] = 1
        temp = min(k, i - 1)
        for j in range(0, temp):
            w = temp - j;
            C[w] = C[w] + C[w - 1]
            print(C[w], end = " ");
        print("\n")
    return C[k]


def main():
    if len(sys.argv) != 3:
        print("Zła liczba argumentów")
        return
    n = int(sys.argv[1])
    k = int(sys.argv[2])
    if n < 0 or k < 0:
        print("Liczby nie mogą być mniejsze od 0")
        return
    if n < k:
        print("n nie może być mniejsze od k")
        return
    print(dwumian(n, k))
    


if __name__ == "__main__":
    main()
