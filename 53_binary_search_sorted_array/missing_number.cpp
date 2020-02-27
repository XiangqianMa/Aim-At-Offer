//
// Created by mxq on 2020/2/27.
//
#include "missing_number.h"


/**
 * @brief 找出有序数组中缺失的数字
 * @param numbers
 * @return
 */
int GetMissingNumber(const vector<int>& numbers){
    if (numbers.empty())
        return -1;
    return GetMissingNumberCore(numbers, 0, numbers.size() - 1);
}


/**
 * @brief 使用二分查找法查找缺失的数字
 * @param numbers
 * @param start
 * @param end
 * @return
 */
int GetMissingNumberCore(const vector<int>& numbers, int start, int end){
    if (start > end)
        return -1;
    int middle = start + (end - start) / 2;
    int result = -1;
    if (numbers[middle] == middle){  // 当前下标和当前值相等，则缺失值出现在右侧
        result = GetMissingNumberCore(numbers, middle + 1, end);
    }
    else if (numbers[middle] > middle){  // 否则出现在左侧
        if (middle - 1 < 0 || numbers[middle - 1] == (middle - 1)) // 左侧不存在数字 或 左侧的数字与下标相等
            result = middle;
        else
            result = GetMissingNumberCore(numbers, start, middle - 1);
    }
    return result;
}