//
// Created by mxq on 2020/2/11.
//

#include "reorder_array.h"


/**
 * @brief 将数组中的奇数放到前半部分，偶数放到后半部分
 * @param data
 */
void ReorderOddEven(vector<int>& data){
    Reorder(data, IsEven);
}


/**
 * @brief 将数组中满足func的数放到后面，不满足的放到前面
 * @param data 数组
 * @param func 函数指针，判断给定的数组是否满足func的条件
 */
void Reorder(vector<int>& data, bool (*func)(int)){
    unsigned int length = data.size();
    unsigned int begin = 0;
    unsigned int end = length - 1;

    while (begin < end){
        while (begin < length && !func(data[begin])){
            begin++;
        }
        while (end >= 0 && func(data[end])){
            end--;
        }

        if (begin < end){
            int temp = data[begin];
            data[begin] = data[end];
            data[end] = temp;
        }
    }
}


/**
 * @brief 判断给定的数是否是偶数
 * @param n
 * @return
 */
bool IsEven(int n){
    return (n & 1) == 0;
}