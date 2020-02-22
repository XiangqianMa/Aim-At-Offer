//
// Created by mxq on 2020/2/22.
//

#include "k_least_numbers.h"


/**
 * @brief 使用维持一个有k个元素的数组的方式找出一个数组中最小的k个数
 * @param numbers
 * @param least_numbers
 * @param k
 */
void FindKLeastNumbers(const vector<int>& numbers, int_set& least_numbers, int k){
    least_numbers.clear();
    if (numbers.empty() || k < 0 || k > numbers.size())
        return;
    auto data_iter = numbers.begin();
    while (data_iter != numbers.end()){
        if (least_numbers.size() < k) {
            least_numbers.insert(*data_iter);
        }
        else{
            auto max_number_iter = least_numbers.begin();
            if (*data_iter < *max_number_iter){
                least_numbers.erase(max_number_iter);
                least_numbers.insert(*data_iter);
            }
        }
        data_iter++;
    }
}