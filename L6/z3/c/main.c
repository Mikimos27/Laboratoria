#include <stdio.h>

#define NUMBERS 6
#define CODE_LEN 4
#define MAX_CODES 1296 // 6^4

typedef struct {
    int V[CODE_LEN];
} Code;

Code Possible[MAX_CODES];
int Possible_Count = 0;

void Generate_Codes() {
    for (int A = 1; A <= NUMBERS; A++) {
        for (int B = 1; B <= NUMBERS; B++) {
            for (int C = 1; C <= NUMBERS; C++) {
                for (int D = 1; D <= NUMBERS; D++) {
                    Possible[Possible_Count].V[0] = A;
                    Possible[Possible_Count].V[1] = B;
                    Possible[Possible_Count].V[2] = C;
                    Possible[Possible_Count].V[3] = D;
                    Possible_Count++;
                }
            }
        }
    }
}

void Score(Code Code_Val, Code Guess, int *Na_swoim, int *Nie_na) {
    int Code_Count[NUMBERS + 1] = {0}; // Array indexing starts from 0
    int Guess_Count[NUMBERS + 1] = {0};

    *Na_swoim = 0;
    *Nie_na = 0;

    for (int I = 0; I < CODE_LEN; I++) {
        if (Code_Val.V[I] == Guess.V[I]) {
            (*Na_swoim)++;
        }

        Code_Count[Code_Val.V[I]]++;
        Guess_Count[Guess.V[I]]++;
    }

    for (int I = 1; I <= NUMBERS; I++) {
        *Nie_na += (Code_Count[I] < Guess_Count[I]) ? Code_Count[I] : Guess_Count[I];
    }

    *Nie_na -= *Na_swoim;
}

int main() {
    Generate_Codes();

    int Move = 1;

    while (Possible_Count > 0) {
        Code Guess = Possible[0];
        int Na_swoim, Nie_na;

        printf("\nRuch %d: ", Move);
        for (int I = 0; I < CODE_LEN; I++) {
            printf("%d ", Guess.V[I]);
        }
        printf("\nNa swoim miejscu: ");
        scanf("%d", &Na_swoim);
        printf("Nie na swoim miejscu: ");
        scanf("%d", &Nie_na);

        if (Na_swoim == 4) {
            printf("Kod odgadniety!\n");
            break;
        }

        Code New_Possible[MAX_CODES];
        int New_Count = 0;

        for (int I = 0; I < Possible_Count; I++) {
            int B, W;
            Score(Possible[I], Guess, &B, &W);

            if (B == Na_swoim && W == Nie_na) {
                New_Possible[New_Count++] = Possible[I];
            }
        }

        for (int I = 0; I < New_Count; I++) {
            Possible[I] = New_Possible[I];
        }

        Possible_Count = New_Count;
        Move++;
    }

    if (Possible_Count == 0) {
        printf("Oszukujesz!\n");
    }

    return 0;
}
