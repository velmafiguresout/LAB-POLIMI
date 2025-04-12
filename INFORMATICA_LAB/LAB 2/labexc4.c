/* Scrivere un programma che legge da stdin un numero codificato (in una forma n1) in 
una «base di partenza» arbitraria b1 compresa tra 2 e 10, e lo converte in una forma 
n2 che esprime il numero codificato in una «base di destinazione» b2, anch’essa 
arbitraria e compresa tra 2 e 10. 
• L’utente dovrà– specificare le due basi (b1 e b2)– digitare il numero da convertire
    (cioè la forma n1 del numero espresso in base b1)
• Il programma dovrà– Verificare che la forma n1 sia valida (cioè contenga solo cifre tra 0 e b1-1)–
Visualizzare il numero convertito (espresso nella forma n2, in base b2, con cifre tra 0 e b2-1) */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#define DIM 50

bool isValid (int b1, char n1[]) {  //n1in valid olup olmadığını kontrol ediyorum
    int len = strlen(n1);
    for (int i = 0; i < len; i++) {
        if (n1[i] < 0 || n1[i] > ('0' + (b1 - 1))) {
            return false;  //invalid
        }
    }
    return true;  //valid
}

//n1'i b2 tabanına çevirmeden önce ilk olarak decimal'e çeviriyorum
int toDecimal (int b1, char n1[]) {
    int decimal = 0;
    int len = strlen(n1);
    for (int i = 0; i < len; i++) {
        decimal = decimal * b1 + (n1[i] - '0');
    }
    return decimal;
}

int changeOfBasis (int decimal, int b2, char n2[]) {
    int i = 0;
    if (decimal == 0) {
        n2[i++] = '0';
    } else {
        while (decimal > 0) {
            n2[i++] = (decimal % b2) + '0';
            decimal /= b2;
        }
    }
    n2[i] = '\0';

    // Diziyi ters çevir
    for (int j = 0; j < i / 2; j++) {
        char temp = n2[j];
        n2[j] = n2[i - j - 1];
        n2[i - j - 1] = temp;
    }
}

int main () {
    int b1, b2;
    char n1[DIM];
    char n2[DIM];
    printf("b1 (2-10): ");
    scanf("%d", &b1);
    printf("\nb2 (2-10): ");
    scanf("%d" ,&b2);
    if (b2 < 2 || b2 > 10) {
        printf("b2 is not valid");
        return 1;
    }

    printf("n1 (number in base %d): ", b1);
    scanf("%s", n1);

    if (!isValid(b1, n1)) {
        printf("is not valid.\n");
        return 1;
    }

    //valid (true) olduğu takdirde işleme devam edeceğim
    int decimal = toDecimal(b1, n1);  //toDecimal fonksiyonundan elde ettiğim değerin
    changeOfBasis(decimal, b2, n2);  //tabanını değiştiriyorum
    printf("coverted %s: %s", n1, n2);

    return 0;
}