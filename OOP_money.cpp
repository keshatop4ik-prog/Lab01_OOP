#include <cstdio>
#include "money.h"

void mnojenya(Money price, int count, Money &total) {
<<<<<<< HEAD
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
=======
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
>>>>>>> 297213e829a5dd1ffd98e10d30fdec9cf4dea25a
}

void umova(const char* fileName) {
    FILE* file = fopen(fileName, "r");
    if (!file) {
        printf("Помилка: файл не знайдено!\n");
        return;
    }

    Money currentTotal = {0, 0};
    int g, k, c;

<<<<<<< HEAD
    while (fscanf(file, "%d %d %d", &g, &k, &c) == 3) {
        if (c <= 0) {
            printf("Помилка: кількість товару (%d) має бути додатною!\n", c);
            continue;
=======
    while (fscanf(file, "%d %d %d", &g, &k, &c) != EOF) {
        if (c <= 0) {
            printf("Помилка: такої кількості товару (%d) не може бути!\n", c);
            fclose(file);
            return;
>>>>>>> 297213e829a5dd1ffd98e10d30fdec9cf4dea25a
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