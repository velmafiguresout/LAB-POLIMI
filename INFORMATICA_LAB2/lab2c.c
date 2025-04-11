/* Si consideri un array v di N interi (come ad esempio v1 e v2 in calce con N=8). Si vuole 
"esplorare" il vettore, iniziando dal primo elemento v[0] e muovendosi con la regola descritta in 
seguito, per stabilire se l'esplorazione porta ad un percorso "infinito”, perché il vettore è ciclico, 
oppure ad un certo punto 
l'esplorazione termina.
Come ci si muove nel vettore: il valore contenuto in ogni elemento, se compreso tra 0 e N-1, 
rappresenta l'indice del prossimo elemento da visitare; se invece è esterno a tale intervallo 
rappresenta un riferimento "errato", che indica una posizione esterna al vettore, e comporta la 
fine del processo di esplorazione. 
Si scriva un programma che stabilisce se un vettore di N interi è ciclico o no. Nell'esempio, v1 è 
ciclico, v2 non lo è. Il programma non deve leggere i numeri da stdin (è inutile!); basta una 
inizializone int v1[N]={3,-3,5,6,2,4,2,11}, v2[N]={5,-6,7,6,2,4,2,9}; Si badi all’algoritmo! */

#include <stdio.h>
#include <stdbool.h>
#define DIM 8

void exploreVector (int v[DIM]) {
    bool visited[DIM] = {false};  //ikinci kere ziyaret edilen indexlerin olup olmadığını burada tutacağım
    int i = 0;
    while (true) {  //sonsuz döngü olarak array'de gezineceğim, ifler benim loopumu şekillendirecek.
        if (i < 0 || i >= DIM) {  //geçersiz indexe geldiysem looptan çıkılacak
            printf("vector is not ciclico.\n");
            printf("exploration is finished.\n");
            break;
        }
        if (visited[i]) {  //eğer bulunduğum index daha önceden kaydedilmişse
            printf("vector is ciclico.\n");
            printf("exploration is finished.\n");
            break; //exploration sonlanacak
        }
        visited[i] = true; //daha önce bulunduğum index
        i = v[i];  //hücrede bulunan değerin index karşılığına gidiyorum
        printf("loop continues...\n");
    }
}


int main () {
    int v1[DIM] = {3,-3,5,6,2,4,2,11};
    exploreVector(v1);
    //int v2[DIM] = {5,-6,7,6,2,4,2,9};
    //exploreVector(v2);


    return 0;
}