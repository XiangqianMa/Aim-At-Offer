//
// Created by mxq on 2020/2/25.
//

#include "inverse_pairs.h"


/**
 * @brief 使用归并排序的思路计算数字序列中的逆序对个数
 * @param numbers
 * @return
 */
int GetInversePairsNumber(const vector<int>& numbers){
    if (numbers.empty() || numbers.size() == 1)
        return 0;
    vector<int> copy(numbers);
    return GetInversePairsNumberCore(copy, 0, numbers.size() - 1);
}


/**
 * @brief 类似于归并排序，在合并时加入逆序对的计算
 * @param numbers
 * @param start
 * @param end
 * @return
 */
int GetInversePairsNumberCore(vector<int>& numbers, int start, int end){
    if (start == end) {
        return 0;
    }
    // 递归计算左半部分和右半部分
    int middle = (start + end) / 2;
    int right_count = GetInversePairsNumberCore(numbers, start, middle);
    int left_count = GetInversePairsNumberCore(numbers, middle + 1, end);

    // 合并左半部分和右半部分
    int left_index = middle;
    int right_index = end;
    int combine_count = 0;
    int combine_index = end - start;
    vector<int> combine(end - start + 1);
    while (left_index >= start && right_index >= middle + 1){
        if (numbers[left_index] > numbers[right_index]){
            combine_count += right_index - middle;
            combine[combine_index--] = numbers[left_index--];
        }
        else {
            combine[combine_index--] = numbers[right_index--];
        }
    }

    // 拷贝剩余的元素
    while (left_index >= start){
        combine[combine_index--] = numbers[left_index--];
    }
    while (right_index >= middle + 1){
        combine[combine_index--] = numbers[right_index--];
    }
    copy(combine.begin(), combine.end(), numbers.begin() + start);
    return combine_count + left_count + right_count;
}