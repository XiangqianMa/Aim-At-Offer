//
// Created by mxq on 2020/2/27.
//

#include "integer_identical_index.h"


/**
 * @brief 找到数组中下标和元素相等的元素
 * @param numbers
 * @return
 */
int GetNumberSameAsIndex(const vector<int>& numbers){
    if (numbers.empty())
        return -1;
    return GetNumberSameAsIndexCore(numbers, 0, numbers.size() - 1);
}


int GetNumberSameAsIndexCore(const vector<int>& numbers, int start, int end){
    if (start > end)
        return -1;

    int middle = start + (end - start) / 2;
    int result = -1;
    if (numbers[middle] == middle) {
        result = middle;
    }
    else if (numbers[middle] > middle){  // 当前值比下标大，则向左侧查找
        result = GetNumberSameAsIndexCore(numbers, start, middle - 1);
    } else{
        result = GetNumberSameAsIndexCore(numbers, middle + 1, end);
    }
    return result;
}