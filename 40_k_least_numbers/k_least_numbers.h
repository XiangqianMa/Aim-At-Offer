//
// Created by mxq on 2020/2/22.
//

#ifndef AIM_AT_OFFER_K_LEAST_NUMBERS_H
#define AIM_AT_OFFER_K_LEAST_NUMBERS_H

#include <vector>
#include <set>

using namespace std;

typedef multiset<int, greater<>> int_set;
typedef multiset<int, greater<>>::iterator int_set_iter;

void FindKLeastNumbers(const vector<int>& numbers, int_set& least_numbers, int k);
#endif //AIM_AT_OFFER_K_LEAST_NUMBERS_H
