#!/usr/bin/env python


def main():
    pn = int(input("Podaj liczbę: "))
    n = pn
    base = int(input("Podaj podstawę: "))
    rem = 0
    pal = 0

    if base == 0:
        print("System liczbowy nie moze opierac sie na zerze")
        return
    if base == 1:
        print("Wszystko w systemie jedynkowym to palindrom")
        return
    if base < 0:
        print("System liczbowy nie moze byc ujemny")
        return
    if pn < 0:
        print("Liczba nie moze byc ujemna")
        return

    while n != 0:
        rem = n % base
        n //= base
        pal = base * pal + rem

    if pn == pal:
        print(f"{pn} jest palindromem")
    else:
        print(f"{pn} nie jest palindromem")


if __name__ == "__main__":
    main()
