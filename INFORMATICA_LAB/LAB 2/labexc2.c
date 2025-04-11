/* Si inizializzi una matrice quadrata m[N][N] con gli interi da 1 a N2 in modo che la prima riga 
contenga i numeri da 1 a N, la seconda da N a 2N, etc. Si definisca N tramite #define
Si stampi poi a video la matrice, e si chieda all’utente di scegliere una cella della matrice 
inserendone le coordinate (i numeri di riga e colonna r e c). Sia K il valore contenuto in 
m[r][c]. Si modifichi quindi la matrice come descritto in seguito, e la si stampi nuovamente:
 • La cella selezionata resta invariata;
 • Tutte le celle della colonna c diverse da quella selezionata (in verde in figura) assumono 
valore 2K
 • A tutte le celle "precedenti" (cioè su righe precedenti a r, oppure sulla stessa riga ma in 
colonne precedenti a c) che non siano nella colonna c si aggiunge K (beige in figura);
 • A tutte le celle "successive" (righe successive, oppure stessa riga ma colonne successive) 
che non siano sulla colonna c si sottrae K (rosa in figura). */

#include <stdio.h>
#define N 5

void stampaMatrice(int matrice[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%4d", matrice[i][j]);
        }
        printf("\n");
    }
}

int main () {
    int R, C;
    int matrice[N][N];

    int counter = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrice[i][j] = counter;
            counter++;
        }
    }

    stampaMatrice(matrice);

    printf("R: ");  //hangi satır
    scanf("%d", &R);
    printf("\nC: ");  //hangi sütun
    scanf("%d", &C);

    int K = matrice[R][C];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == R && j == C) {  //seçilen hücreyle aynıysa
                continue;  //bir şey yapılmayacak
            }
            if (j == C) {
                matrice[i][j] = 2 * K;  //seçilen hücrenin bütün kolonunu 2'yle çarpıyorum
            }
            else if ((i < R) || ((i == R) && (j < C))) {
                matrice[i][j] += K;
            }
            else if ((i > R) || ((i == R) && (j > C))) {
                matrice[i][j] -= K;
            }
        }
    }
    stampaMatrice(matrice);

    return 0;
}