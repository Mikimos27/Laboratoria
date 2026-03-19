#!/usr/bin/env python

def main():
    return test()


def test():
    l = [0,2,24,17,3,1023,1204,1203]
    for i in range(0, len(l)):
        if prime(l[i]):
            print(f"{l[i]} pierwsza\n")
        else:
            print(f"{l[i]} nie pierwsza\n")

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
    main()
