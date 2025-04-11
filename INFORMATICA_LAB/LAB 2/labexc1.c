/* Si leggano da stdin due parole (da leggersi come stringhe, cioè array di caratteri) e 
si verifichi se sono una l'anagramma dell'altra. 
Si badi a verificare bene le occorrenze delle lettere: 
PENTOLA e POLENTA sono anagrammi, ma TONNO e TONTO non lo sono, anche 
se sono formate dalle stesse lettere (T, O, N), hanno pari lunghezza, e… in un certo 
senso sono anche sinonimi 
Riassumendo:
TROGOLO, ZANGOLA NO
PENTOLA, POLENTA  SÌ 
TONNO, TONTO NO */

#include <stdio.h>
#include <stdbool.h>
#define DIM 10

bool isAnagram (char* string1, char* string2) {
    if (strlen(string1) != strlen(string2)) {  //uzunlukları aynı değilse direkt false
        return false;
    }
    for (int i = 0; i < DIM; i++) {
        int count = 0;  //her karakter eşleşmesini kaydetmek için 'count' değişkeni tutuyorum
        for (int j = 0; j < DIM; j++) {
            if (string1[i] == string2[j]) {  //string2'nin indexi string1in indexiyle eşit olduğu an 
                string2[j] = '\0';  //string2den bulduğum karakteri siliyorum
                count++;
                break;  //eğer string1'deki bir karakteri string2'de bir kere bile olsa bulmuşsam looptan çıkıyorum
            }  //içerdeki looptan çıkıp tekrar dıştaki loopa dönüyorum
        }  //bu sayede string1'in tüm indexlerini sırayla string2'yi dolaşarak eşleşme var mı diye bakıyorum
        if (!count) {
            return false;
        }
    }
}

int main () {
    char string1[DIM];
    char string2[DIM];
    printf("enter a string: \n");
    gets(string1);
    printf("enter a string: \n");
    gets(string2);

    if (isAnagram(string1, string2)) {
        printf("anagram.\n");
    }
    else {
        printf("not anagram.\n");
    }

    return 0;
}