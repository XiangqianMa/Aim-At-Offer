//
// Created by mxq on 2020/2/21.
//

#ifndef AIM_AT_OFFER_MORE_THAN_HALF_NUMBER_H
#define AIM_AT_OFFER_MORE_THAN_HALF_NUMBER_H

#include <vector>
#include <cstdlib>

using namespace std;


unsigned int RandomInRange(unsigned int start, unsigned int end);
int Partition(vector<int>& numbers, int start, int end);
bool CheckMoreThanHalf(const vector<int>& numbers, int& number);
int MoreThanHalfNumber(vector<int>& numbers);
#endif //AIM_AT_OFFER_MORE_THAN_HALF_NUMBER_H
