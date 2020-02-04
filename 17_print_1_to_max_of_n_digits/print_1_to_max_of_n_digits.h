//
// Created by mxq on 2020/2/4.
//

#ifndef AIM_AT_OFFER_PRINT_1_TO_MAX_OF_N_DIGITS_H
#define AIM_AT_OFFER_PRINT_1_TO_MAX_OF_N_DIGITS_H

#include <string>
#include <iostream>

using namespace std;

bool IncrementNumber(string &number);
void PrintNumber(const string &number);
void Print1ToMaxOfNDigits(int n);
void Print1ToMaxOfNDigitsRecursively(int n);
void Print1ToMaxOfNDigitsRecursivelyCore(string &number, unsigned int index);
#endif //AIM_AT_OFFER_PRINT_1_TO_MAX_OF_N_DIGITS_H
