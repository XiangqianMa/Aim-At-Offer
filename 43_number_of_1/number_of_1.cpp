//
// Created by mxq on 2020/2/24.
//

#include "number_of_1.h"


/**
 * @brief 求1~n范围内的数中1的个数
 * @param n
 * @return
 */
int NumberOf1Between1AndN(int n){
    if (n <= 0)
        return 0;
    string string_n = to_string(n);
    return NumberOf1Core(string_n, 0);
}


int NumberOf1Core(const string& string_n, unsigned int start_index){
    if (string_n.empty() || start_index == string_n.size() ||
        string_n[start_index] < '0' || string_n[start_index] > '9')
        return 0;

    int first = string_n[start_index] - '0';
    int length = string_n.size() - start_index;

    // n为个位数的情况
    if (length == 1 && first == 0)
        return 0;
    if (length == 1 && first > 0)
        return 1;

    // 处理最高位为1的情况
    int number_first_digit = 0; // 1位于最高为的数的数目
    if (first > 1)
        number_first_digit = PowerBased10(length - 1);
    else
        number_first_digit = stoi(string(string_n.begin() + start_index + 1, string_n.end())) + 1;

    // 除最高位外的数位中的数目
    int number_of_other_digits = first * (length - 1) * PowerBased10(length - 2);
    int number_recursive = NumberOf1Core(string_n, start_index + 1);

    return number_first_digit + number_of_other_digits + number_recursive;
}


int PowerBased10(unsigned int n){
    int result = 1;
    for (int i = 0; i < n; i++)
        result *= 10;
    return result;
}