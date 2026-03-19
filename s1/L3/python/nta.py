import sys

def nta(n):
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



def main():
    if len(sys.argv) != 2:
        print("Zła liczba argumentów")
        return
    n = int(sys.argv[1])
    if n < 0:
        print("Liczby nie mogą być mniejsze od 0")
        return
    print(nta(n))
    


if __name__ == "__main__":
    main()
