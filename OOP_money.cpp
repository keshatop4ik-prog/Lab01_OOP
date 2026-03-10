#include <cstdio>
#include "money.h"

void mnojenya(Money price, int count, Money &total) {
    total.grn = price.grn * count + (price.kop * count) / 100;
    total.kop = (price.kop * count) % 100;
}

void dodavanya(Money &total, Money itemSum) {
    total.grn += itemSum.grn + (total.kop + itemSum.kop) / 100;
    total.kop = (total.kop + itemSum.kop) % 100;
}

void zaokruhlenya(Money &m) {
    int last_digit = m.kop % 10;
    m.kop = (last_digit < 8) ? (m.kop - last_digit) : (m.kop + (10 - last_digit));
    m.grn += m.kop / 100;
    m.kop %= 100;
}

void umova(const char* fileName) {
    FILE* file = fopen(fileName, "r");
    if (!file) {
        printf("Помилка: файл не знайдено!\n");
        return;
    }

    Money currentTotal = {0, 0};
    int g, k, c;

    while (fscanf(file, "%d %d %d", &g, &k, &c) == 3) {
        if (c <= 0) {
            printf("Помилка: кількість товару (%d) має бути додатною!\n", c);
            continue;
        }

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