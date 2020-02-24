//
// Created by mxq on 2020/2/24.
//

#include "digits_in_sequence.h"


/**
 * @brief 计算数字序列的第index位的数字
 * @param index
 * @return
 */
int DigitAtIndex(int index){
    if (index < 0)
        return -1;

    int digits_number = 1;
    while (true){
        int numbers = CountOfInteger(digits_number);
        if (index < digits_number * numbers){
            return NumberAtIndex(index, digits_number);
        }
        index = index - digits_number * numbers;
        digits_number++;
    }
}


/**
 * @brief 计算位数为digits_number的数字的个数，例如，2位数的个数位90；3位数的个数为900
 * @param digits_number
 * @return
 */
int CountOfInteger(int digits_number){
    int count;
    if (digits_number == 1)
        count = 10;
    else{
        count = 1;
        for (int i = 0; i < digits_number - 1; i++)
            count *= 10;
        count *= 9;
    }
    return count;
}


/**
 * @brief 计算位数为digits_number的数字序列的第index位的数字
 * @param index 索引
 * @param digits_number 位数
 * @return
 */
int NumberAtIndex(int index, int digits_number){
    // 所查找的索引对应第number_index个数字
    int number_index = index / digits_number;
    // 对应第number_index个数字的第digit_index个位
    int digit_index = index % digits_number;
    int begin_number = CalculateBeginNumber(digits_number);  // 当前位数的数字的起始数字
    int number = begin_number + number_index;  // index所处的数字
    for (int i = 0; i < digits_number - digit_index - 1; i++){
        number /= 10;
    }
    return number % 10;
}


/**
 * @brief 计算位数为digits_number的范围的起始数字，例如，3位数的起始数字是100
 * @param digits_number
 * @return
 */
int CalculateBeginNumber(int digits_number){
    int begin_number = 0;
    if (digits_number > 1) {
        int temp_number = 1;
        for (int i = 0; i < digits_number - 1; i++) {
            temp_number *= 10;
        }
        begin_number = temp_number;
    }
    return begin_number;
}