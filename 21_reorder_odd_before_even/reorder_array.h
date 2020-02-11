//
// Created by mxq on 2020/2/11.
//

#ifndef AIM_AT_OFFER_REORDER_ARRAY_H
#define AIM_AT_OFFER_REORDER_ARRAY_H

#include <vector>

using namespace std;

void ReorderOddEven(vector<int>& data);
void Reorder(vector<int>& data, bool (*func)(int));
bool IsEven(int n);
#endif //AIM_AT_OFFER_REORDER_ARRAY_H
