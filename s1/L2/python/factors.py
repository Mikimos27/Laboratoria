#!/usr/bin/env python

def main(num):
    org = num
    len = num // 2 + 1
    if num == 0:
        return 1
    if num == 1:
        print("1")
        return 0
    if prime(num):
        print(num)
        return 0


    count = 0
    while num % 2 == 0:
        count += 1
        num = num // 2
    if count == 1:
        print("2,", end = " ")
    if count > 1:
        print(f"2^{count},", end = " ")
    i = 3
    while i <= len:
        count = 0
        while num % i == 0:
            count += 1
            num = num // i
        if count == 1:
            print(f"{i},", end = " ")
        if count > 1:
            print(f"{i}^{count},", end = " ")
        i = i + 2
    if num > 1:
        print(org)
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
    for i in [105, 192, 1]:
        main(i)
        print("")
