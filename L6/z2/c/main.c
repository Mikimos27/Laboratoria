#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int n;
int *position;
bool *bije_wiersz;
bool *bije_przek1;
bool *bije_przek2;
long long sol_count = 0;

void print_sol() {
    sol_count++;
    for(int i = 0; i < n; i++) {
        printf("%d ", position[i] + 1);
    }
    putchar('\n');
}

void ustaw(int i) {
    for (int j = 0; j < n; j++) {
        int idx1 = i + j;
        int idx2 = i - j + (n - 1);
        if(!(bije_wiersz[j] || bije_przek1[idx1] || bije_przek2[idx2])) {
            position[i] = j;
            bije_wiersz[j] = bije_przek1[idx1] = bije_przek2[idx2] = true;

            if(i < n - 1) ustaw(i + 1);
            else print_sol();

            position[i] = -1;
            bije_wiersz[j] = bije_przek1[idx1] = bije_przek2[idx2] = false;
        }
    }
}

int main(int argc, char *argv[]) {
    if(argc < 2) return 1;
    if(sscanf(argv[1], "%d", &n) != 1) return 1;

    position = malloc(n * sizeof(int));
    bije_wiersz = malloc(n * sizeof(bool));
    bije_przek1 = malloc((2 * n - 1) * sizeof(bool));
    bije_przek2 = malloc((2 * n - 1) * sizeof(bool));

    if(!position || !bije_wiersz || !bije_przek1 || !bije_przek2) {
        fprintf(stderr, "malloc error\n");
        return 1;
    }

    for (int i = 0; i < n; i++) position[i] = -1;
    for (int i = 0; i < n; i++) bije_wiersz[i] = false;
    for (int i = 0; i < 2 * n - 1; i++) bije_przek1[i] = bije_przek2[i] = false;

    ustaw(0);

    printf("Num of solutions: %lld\n", sol_count);

    free(position);
    free(bije_wiersz);
    free(bije_przek1);
    free(bije_przek2);
    return 0;
}

