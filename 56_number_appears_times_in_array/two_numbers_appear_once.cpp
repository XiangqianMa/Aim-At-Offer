//
// Created by mxq on 2020/2/28.
//

#include "two_numbers_appear_once.h"


/**
 * @brief 找出数组中只出现两次的数字
 * @param numbers
 * @param num1
 * @param num2
 */
void FindNumbersAppearOnce(const vector<int>& numbers, int& num1, int& num2){
    if (numbers.empty())
        return;

    int result_exclusive_or = 0;
    for (auto number: numbers)
        result_exclusive_or ^= number;

    int index_bit = FindBit1Index(result_exclusive_or);
    num1 = 0;
    num2 = 0;
    for (auto number: numbers){
        if (IsBit1(number, index_bit))
            num1 ^= number;
        else
            num2 ^= number;
    }
}


/**
 * @brief 找出number中，从右起，为1的二进制位的索引
 * @param number
 * @return
 */
int FindBit1Index(int number){
    int index = 0;
    while ((number & 1) == 0 && (index < 8 * sizeof(int))){
        index++;
        number = number >> 1;
    }
    return index;
}


/**
 * @brief 判断number二进制的右数起的index_bit位是否为1
 * @param number
 * @param index_bit
 * @return
 */
bool IsBit1(int number, int index_bit){
    number = number >> index_bit;
    return (number & 1);
}