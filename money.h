#ifndef MONEY_H
#define MONEY_H

struct Money {
    int grn;
    short int kop;
};

void mnojenya(Money price, int count, Money &total);
void dodavanya(Money &total, Money itemSum);
void zaokruhlenya(Money &m);
void umova(const char* fileName);

#endif