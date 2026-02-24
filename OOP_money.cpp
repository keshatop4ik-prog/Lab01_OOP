#include <cstdio>
#include "money.h"

void mnojenya(Money price, int count, Money &total) {
    long all_kop = (price.grn * 100 + price.kop) * count;
    total.grn = all_kop / 100;
    total.kop = all_kop % 100;
}

void dodavanya(Money &total, Money itemSum) {
    long all_kop = (total.grn * 100 + total.kop) + (itemSum.grn * 100 + itemSum.kop);
    total.grn = all_kop / 100;
    total.kop = all_kop % 100;
}

void zaokruhlenya(Money &m) {
    int last_number = m.kop % 10;
    if (last_number < 8) {
        m.kop -= last_number;
    } else {
        m.kop += (10 - last_number);
    }
    if (m.kop >= 100) {
        m.grn++;
        m.kop = 0;
    }
}

void umova(const char* fileName) {
    FILE* file = fopen(fileName, "r");
    if (!file) return;

    Money currentTotal = {0, 0};
    int g, k, c;

    while (fscanf(file, "%d %d %d", &g, &k, &c) != EOF) {
        Money price = {g, (short int)k};
        Money itemSum;
        mnojenya(price, c, itemSum);
        dodavanya(currentTotal, itemSum);
    }
    fclose(file);

    Money finalPay = currentTotal;
    zaokruhlenya(finalPay);

    printf("Пампарампампам\n");
    printf("Сума: %d грн %02d коп\n", currentTotal.grn, currentTotal.kop);
    printf("Заокруглено: %d грн %02d коп\n", finalPay.grn, finalPay.kop);
}