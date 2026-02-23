#ifndef MONEY_H
#define MONEY_H

struct Money {
    int grn;
    short int kop;
};
Money add(Money m1, Money m2);
Money multiply(Money m, int count);
Money zaokruhlenya(Money m);
void printMoney(const char* label, Money m);
#endif