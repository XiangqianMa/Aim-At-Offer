//
// Created by mxq on 2020/2/24.
//

#include "greatest_sum_of_sub_array.h"


/**
 * @brief 求数组中连续子数组的最大和，此编码方式同时也蕴含着动态规划的思想
 * @param data
 * @return
 */
int GreatestSumOfSubArray(const vector<int>& data){
    if (data.empty())
        return 0;
    int max_sum = 0x80000000;
    int current_sum = 0;
    for (auto element: data){
        // 当前和小于0，则重启子数组
        if (current_sum < 0){
            current_sum = 0;
        }
        current_sum += element;
        if (current_sum > max_sum)
            max_sum = current_sum;
    }
    return max_sum;
}