//
// Created by mxq on 2020/2/28.
//

#ifndef AIM_AT_OFFER_TWO_NUMBERS_APPEAR_ONCE_H
#define AIM_AT_OFFER_TWO_NUMBERS_APPEAR_ONCE_H

#include <vector>

using namespace std;

bool IsBit1(int number, int index_bit);
int FindBit1Index(int number);
void FindNumbersAppearOnce(const vector<int>& numbers, int& num1, int& num2);
#endif //AIM_AT_OFFER_TWO_NUMBERS_APPEAR_ONCE_H
