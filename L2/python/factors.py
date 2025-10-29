#!/usr/bin/env python

def main(num):
    org = num
    if num == 0:
        return 1
    if num == 1:
        print("1")
        return 0
    if prime(num):
        print(num)
        return 0;

    l: list = []

    while num % 2 == 0:
        l.append(2)
        num = num // 2
    i = 3
    while i * i <= num + 1:
        while num % i == 0:
            l.append(i)
            num = num // i
        i = i + 2
    if num > 1:
        l.append(num)
    print(f"{org} = {l}")
    return 0








def prime(p):
    if p <= 1:
        return False
    if p == 2:
        return True
    if p % 2 == 0:
        return False
    
    i = 3
    while i * i <= p:
        if p % i == 0:
            return False
        i = i + 1
    return True

if __name__ == "__main__":
    for i in range(0, 200):
        main(i)
