//
// Created by mxq on 2020/2/25.
//

#include "first_not_repeating_char.h"


/**
 * @brief 找到字符串中第一个重复次数为1的字符
 * @param str
 * @return
 */
char FirstNotRepeatingChar(const string& str){
    if (str.empty())
        return '\0';
    vector<int> char_repeating_number(256, 0);

    for (auto current_char: str){
        char_repeating_number[current_char]++;
    }

    for (auto current_char: str){
        if (char_repeating_number[current_char] == 1)
            return current_char;
    }
    return '\0';
}