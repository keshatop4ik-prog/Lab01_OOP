#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include "money.h"
#include <windows.h>
using namespace std;
int main() {
    system("chcp 65001 > nul");
    FILE* file = fopen("input.txt", "r");
    if (!file) {
        printf("Файл input.txt не найшло\n");
        return 1;
    }
    Money totalSum = { 0, 0 };
    int g, k, count;
    while (fscanf(file, "%d %d %d", &g, &k, &count) != EOF) {
        Money price = { g, k };
        Money subTotal = multiply(price, count);
        totalSum = add(totalSum, subTotal);
    }
    fclose(file);
    Money finalPay = zaokruhlenya(totalSum);
    printf("Кінцевий результат (типо чек)\n");
    printMoney("Загальна сума короче", totalSum);
    printMoney("До сплати заокруглено", finalPay);
    printf("Та й все\n");
    return 0;
}