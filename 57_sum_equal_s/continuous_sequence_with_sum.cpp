//
// Created by mxq on 2020/2/29.
//

#include "continuous_sequence_with_sum.h"


/**
 * @brief 找出和为sum的正整数序列
 * @param sum
 */
void FindContinuousSequenceWithSum(int sum){
    if (sum < 3)
        return;

    int small = 1;
    int big = 2;
    int current_sum = 3;
    int middle = (1 + sum) / 2;
    while (small < middle){
        if (current_sum == sum)
            PrintSequence(small, big);
        // 移除最小值，直到序列和小于或等于sum
        while (current_sum > sum && small < middle){
            current_sum -= small;
            small++;
            if (current_sum == sum)
                PrintSequence(small, big);
        }
        // 向更大的方向拓展区间
        big++;
        current_sum += big;
    }
}


void PrintSequence(int start, int end){
    for (int i = start; i <= end; i++)
        cout << i << ' ';
    cout << endl;
}