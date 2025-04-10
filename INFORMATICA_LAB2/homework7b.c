/* Çağrıldığında ekrana 01.01.1900 ve 31.12.2100 arasında rastgele bir tarihi yazan printRandomDate isimli 
fonksiyonu yazınız. Metodun ekrana yazdırdığı tarih geçerli bir tarih olmalıdır. Rasgele tarihin Şubat ayına denk 
gelmesi durumunda, seçilen yılın artık yıl olup olmamasına göre, Şubat ayı 29 çekebilecektir. Tarih ekrana 
aşağıdaki formatta yazdırılacaktır:  
11th July 1983 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define randomize() srand(time(NULL))

const char* months[12] = {"january", "february", "march", "april", "june", "july", "august", "september", "october", "november", "december"};

const char* daySuffix (int day) {
    if (day >= 11 && day <= 13) {
        return "th";
    }
    switch (day % 10) {
        case 1: return "st";
        case 2: return "nd";
        case 3: return "rd";
        default: return "th";
    }
}

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void printRandomDate() {
    int year = 1900 + rand() % 201;
    int month = 1 + rand() % 12;
    int day;

    if (month == 2) {  //şubatsa
        day = 1 + rand() % (isLeapYear(year) ? 29 : 28);
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) { // 30 çeken aylar
        day = 1 + rand() % 30;
    }
    else { // 31 çeken aylar
        day = 1 + rand() % 31;
    }
    
    printf("%d%s %s %d", day, daySuffix(day), months[month - 1], year);
}

int main () {
    randomize();
    printRandomDate();

    return 0;
}