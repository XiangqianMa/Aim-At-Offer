//
// Created by mxq on 2020/3/2.
//

#include "add_two_numbers.h"


/**
 * @brief 使用位运算完成加法运算
 * @param num1
 * @param num2
 * @return
 */
int AddTwoNumbers(int num1, int num2){
    int sum;
    int carry;
    do{
        sum = num1 ^ num1;
        carry = (num1 & num2) << 1;
        num1 = sum;
        num2 = carry;
    } while (num2 != 0);
    return sum;
}