//
// Created by mxq on 2020/2/29.
//

#include "two_numbers_with_sum.h"


/**
 * @brief 在排序数组中查找和位sum的两个数
 * @param data
 * @param sum
 * @param num1
 * @param num2
 * @return
 */
bool FindNumbersWithSum(const vector<int>& data, int sum, int& num1, int& num2){
    if (data.empty())
        return false;

    auto begin = data.begin();
    auto end = data.end() - 1;
    bool found = false;
    while (begin < end){
        if ((*begin + *end) == sum){
            num1 = *begin;
            num2 = *end;
            found = true;
            break;
        }
        if ((*begin + *end) > sum)
            end--;
        else
            begin++;
    }
    return found;
}