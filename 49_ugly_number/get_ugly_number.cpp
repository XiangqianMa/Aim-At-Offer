//
// Created by mxq on 2020/2/25.
//

#include "get_ugly_number.h"


/**
 * @brief 找到指定index的丑数
 * @param index
 * @return
 */
int GetUglyNumber(int index){
    if (index <= 0)
        return 0;

    vector<int> ugly_numbers(index);
    ugly_numbers[0] = 1;

    auto multiply_2 = ugly_numbers.begin();
    auto multiply_3 = ugly_numbers.begin();
    auto multiply_5 = ugly_numbers.begin();

    for (int ugly_number_index = 1; ugly_number_index < index; ugly_number_index++){
        int current_ugly_number = Min(*multiply_2 * 2, *multiply_3 * 3, *multiply_5 * 5);
        ugly_numbers[ugly_number_index] = current_ugly_number;

        // 找到ugly_numbers中乘以 2， 3， 5 后大于current_ugly_number的第一个元素
        while (*multiply_2 * 2 <= current_ugly_number)
            multiply_2++;
        while (*multiply_3 * 3 <= current_ugly_number)
            multiply_3++;
        while (*multiply_5 * 5 <= current_ugly_number)
            multiply_5++;
    }
    return ugly_numbers[index - 1];
}


int Min(int number1, int number2, int number3){
    int result = number1 < number2? number1: number2;
    result = result < number3? result: number3;
    return result;
}