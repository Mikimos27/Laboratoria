import sys

n = 0
position = []
bije_wiersz = []
bije_przek1 = []
bije_przek2 = []
sol_count = 0

def print_sol():
    global n 
    global position 
    global bije_wiersz
    global bije_przek1
    global bije_przek2
    global sol_count
    sol_count += 1
    for i in range(0, n):
        print(f"{position[i] + 1}", end = " ")
    print("")

def ustaw(i):
    global n 
    global position 
    global bije_wiersz
    global bije_przek1
    global bije_przek2
    global sol_count
    for j in range(0, n):
        idx1 = i + j
        idx2 = i - j + (n - 1)
        if False == (bije_wiersz[j] or bije_przek1[idx1] or bije_przek2[idx2]):
            position[i] = j
            bije_wiersz[j] = bije_przek1[idx1] = bije_przek2[idx2] = True

            if(i < n - 1):
                ustaw(i + 1)
            else:
                print_sol()
            position[i] = -1
            bije_wiersz[j] = bije_przek1[idx1] = bije_przek2[idx2] = False


def init_list(l, size, init):
    for i in range(0, size):
        l.append(init)

def main():
    if len(sys.argv) < 2:
        return 1
    global n 
    global position 
    global bije_wiersz
    global bije_przek1
    global bije_przek2
    global sol_count
    n = int(sys.argv[1])
    init_list(position, n, -1)
    init_list(bije_wiersz, n, False)
    init_list(bije_przek1, 2*n - 1, False)
    init_list(bije_przek2, 2*n - 1, False)
    ustaw(0)
    print(f"Num of sols: {sol_count}")

if __name__ == "__main__":
    print(f"return {main()}")
