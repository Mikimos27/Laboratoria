import sys

def reverse(arr, b, s):
    for i in range(0, s // 2):
        temp = arr[b + i]
        arr[b + i] = arr[b + s - i - 1];
        arr[b + s - i - 1] = temp

def permute(arr):
    i = len(arr) - 1
    while i >= 1:
        if arr[i] > arr[i - 1]:
            break
        i -= 1
    if i == 0:
        return
    i = i - 1
    min = len(arr) + 1
    min_index = 0
    for j in range(i + 1, len(arr)):
        if min > arr[j] and arr[j] > arr[i]:
            min = arr[j]
            min_index = j

    temp = arr[min_index]
    arr[min_index] = arr[i]
    arr[i] = temp
    reverse(arr, i + 1, len(arr) - i - 1)

def fact(n):
    if n == 0 or n == 1:
        return 1
    return n * fact(n - 1)

def abs(n):
    if n >= 0:
        return n
    return -n

def check_safe(arr):
    for i in range(0, len(arr)):
        for j in range(i + 1, len(arr)):
            if abs(arr[i] - arr[j]) == abs(i - j):
                return False
    return True

def main():
    if len(sys.argv) < 2:
        print("Za mało argumentów\n")
        return
    arr = []
    for i in range(0, int(sys.argv[1])):
        arr.append(i + 1)
    l = int(sys.argv[1])
    perms = fact(l)
    sols = 0
    for i in range(0, perms):
        if check_safe(arr):
            sols += 1
            print(arr)
        permute(arr)
    print(f"Num of sols: {sols}\n")
if __name__ == "__main__":
    main()
