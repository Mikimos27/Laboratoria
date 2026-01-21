NUMBERS = 6
CODE_LEN = 4
MAX_CODES = 1296  # 6^4

class Code:
    def __init__(self):
        self.V = [0] * CODE_LEN

Possible = []
Possible_Count = 0

def generate_codes():
    global Possible_Count
    for A in range(1, NUMBERS + 1):
        for B in range(1, NUMBERS + 1):
            for C in range(1, NUMBERS + 1):
                for D in range(1, NUMBERS + 1):
                    code = Code()
                    code.V = [A, B, C, D]
                    Possible.append(code)
                    Possible_Count += 1

def score(code_val, guess):
    Na_swoim = 0
    Nie_na = 0
    Code_Count = [0] * (NUMBERS + 1)
    Guess_Count = [0] * (NUMBERS + 1)

    for i in range(CODE_LEN):
        if code_val.V[i] == guess.V[i]:
            Na_swoim += 1
        Code_Count[code_val.V[i]] += 1
        Guess_Count[guess.V[i]] += 1

    for i in range(1, NUMBERS + 1):
        Nie_na += min(Code_Count[i], Guess_Count[i])

    Nie_na -= Na_swoim
    return Na_swoim, Nie_na

def main():
    global Possible_Count
    global Possible
    generate_codes()

    Move = 1

    while Possible_Count > 0:
        guess = Possible[0]
        print(f"\nRuch {Move}: {' '.join(map(str, guess.V))}")

        Na_swoim = int(input("Na swoim miejscu: "))
        Nie_na = int(input("Nie na swoim miejscu: "))

        if Na_swoim == 4:
            print("Kod odgadniety!")
            break

        New_Possible = []
        
        for i in range(Possible_Count):
            B, W = score(Possible[i], guess)
            if B == Na_swoim and W == Nie_na:
                New_Possible.append(Possible[i])

        Possible = New_Possible
        Possible_Count = len(Possible)
        Move += 1

    if Possible_Count == 0:
        print("Oszukujesz!")

if __name__ == "__main__":
    main()
