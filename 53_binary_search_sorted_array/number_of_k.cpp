//
// Created by mxq on 2020/2/27.
//

#include "number_of_k.h"


/**
 * @brief 统计在排序数组中数字k重复出现的次数
 * @param numbers
 * @param k
 * @return
 */
int GetNumberOfK(const vector<int>& numbers, int k){
    if (numbers.empty())
        return 0;
    int first_index = GetFirstPosition(numbers, k, 0, numbers.size() - 1);
    int last_index = GetLastPosition(numbers, k, 0, numbers.size() - 1);

    if (first_index == -1 || last_index == -1)
        return 0;
    return last_index - first_index + 1;
}


/**
 * @brief 找到k在排序数组中第一次出现的位置
 * @param numbers
 * @param k
 * @param start
 * @param end
 * @return
 */
int GetFirstPosition(const vector<int>& numbers, int k, int start, int end){
    if (start > end)
        return -1;

    int middle = start + (end - start) / 2;
    int first_index = -1;
    if (numbers[middle] > k){
        first_index = GetFirstPosition(numbers, k, start, middle - 1);
    }
    else if (numbers[middle] < k){
        first_index = GetFirstPosition(numbers, k, middle + 1, end);
    }
    else{
        if (middle - 1 < 0 || numbers[middle - 1] != k)
            first_index = middle;
        else
            first_index = GetFirstPosition(numbers, k, start, middle - 1);
    }
    return first_index;
}


/**
 * @brief 在排序数组中查找k最后一次出现的位置
 * @param numbers
 * @param k
 * @param start
 * @param end
 * @return
 */
int GetLastPosition(const vector<int>& numbers, int k, int start, int end){
    if (start > end)
        return -1;

    int middle =  start + (end - start) / 2;
    int last_index = -1;
    if (numbers[middle] > k){
        last_index = GetLastPosition(numbers, k, start, middle - 1);
    }
    else if (numbers[middle] < k){
        last_index = GetLastPosition(numbers, k, middle + 1, end);
    }
    else{
        if (middle + 1 > end || numbers[middle + 1] != k)
            last_index = middle;
        else
            last_index = GetLastPosition(numbers, k, middle + 1, end);
    }
    return last_index;
}