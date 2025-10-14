#!/usr/bin/env python

def main():
    a = int(input("Podaj a: "))
    b = int(input("Podaj b: "))
    pa = a
    pb = b

    if a < 0 or b < 0:
        print("Liczby nie moga byc mniejsze od 0")
        return
    if a == 0 or b == 0:
        printf(f"NWD({a}, {b}) = 0")
        return

    while b != 0:
        if a < b:
            a, b = b, a
        else:
            a = a % b

    print(f"NWD({pa}, {pb}) = {a}")


if __name__ == "__main__":
    main()
