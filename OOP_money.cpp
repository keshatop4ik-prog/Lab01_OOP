#include "money.h"
#include <cstdio>

using namespace std;

Money add(Money m1, Money m2) {
    Money result;
    int total_k = m1.kop + m2.kop;
    result.grn = m1.grn + m2.grn + (total_k / 100);
    result.kop = total_k % 100;
    return result;
}

Money multiply(Money m, int count) {
    long total_kop = (m.grn * 100 + m.kop) * count;
    Money result;
    result.grn = total_kop / 100;
    result.kop = total_kop % 100;
    return result;
}

Money zaokruhlenya(Money m) {
    int ostanya_cyfra = m.kop % 10;
    if (ostanya_cyfra < 5) {
        m.kop -= ostanya_cyfra;
    } else {
        m.kop += (10 - ostanya_cyfra);
    }
    if (m.kop >= 100) {
        m.grn += 1;
        m.kop = 0;
    }
    return m;
}
void printMoney(const char* label, Money m) {
    printf("%s: %d грн %02d коп\n", label, m.grn, m.kop);
}