#!/usr/bin/env python

def euklides(a: int, b: int):
    while b != 0:
        a = a % b
        a, b = b, a
    return a


def main():
    a = int(input("Podaj a: "))
    b = int(input("Podaj b: "))
    pa = a
    pb = b

    if a < 0 or b < 0:
        print("Liczby nie moga byc mniejsze od 0")
        return
    if a == 0 or b == 0:
        print(f"NWD({a}, {b}) = {a + b}")
        return

    a = euklides(a, b)

    print(f"NWD({pa}, {pb}) = {a}")


if __name__ == "__main__":
    main()
