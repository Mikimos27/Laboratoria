#!/usr/bin/env python
import math


def main():
    a = float(input("a = "))
    b = float(input("b = "))
    c = float(input("c = "))

    if a != 0:
        delta = b ** 2 - 4 * a * c
        if delta < 0:
            print("x nie jest liczbą rzeczywistą")
        elif delta == 0:
            x1 = -b / 2 / a
            print(f"x = {x1}")
        else:
            x1 = (-b - math.sqrt(delta)) / 2 / a
            x2 = (-b + math.sqrt(delta)) / 2 / a
            print(f"x1 = {x1}\nx2 = {x2}")

    elif b != 0:
        x1 = -c / b
        print(f"x = {x1}")
    elif c == 0:
        print("x należy do liczb rzeczywistych")
    else:
        printf("x nie istnieje")



if __name__ == "__main__":
    main()
