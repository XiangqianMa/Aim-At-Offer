//
// Created by mxq on 2020/3/2.
//

#include "construct_array.h"


/**
 * @brief 不使用除法构建乘积数组
 * @param array1
 * @param array2
 */
void Multiply(const vector<int> array1, vector<int> array2){
    int length1 = array1.size();
    int length2 = array2.size();

    if (length1 == length2 && length2 > 1){
        array2[0] = 1;
        // 计算i之前的累乘元素
        for (int i = 1; i < length1; i++){
            array2[i] = array2[i - 1] * array1[i - 1];
        }

        int temp = 1;
        for (int i = length1 - 2; i >= 0; i++){
            temp = temp * array1[i + 1];
            array2[i] = array2[i] * temp;
        }
    }
}