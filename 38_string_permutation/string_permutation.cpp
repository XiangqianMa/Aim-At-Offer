//
// Created by mxq on 2020/2/19.
//

#include "string_permutation.h"


/**
 * @brief 输出字符串的排列
 * @param original_string
 */
void StringPermutation(string& original_string){
    if (original_string.empty())
        return;
    StringPermutation(original_string, 0);
}


/**
 * @brief 递归产生字符串的排列
 * @param original_string 原始的字符串
 * @param begin_index 开始下标
 */
void StringPermutation(string& original_string, string::size_type begin_index){
    if (begin_index == original_string.size() - 1){
        PrintString(original_string);
        return;
    }

    for (auto index = begin_index; index < original_string.size(); index++){
        char temp_char = original_string[begin_index];
        original_string[begin_index] = original_string[index];
        original_string[index] = temp_char;

        StringPermutation(original_string, begin_index + 1);

        // 将交换过的两个字符交换回去，再继续交换下一个字符
        temp_char = original_string[begin_index];
        original_string[begin_index] = original_string[index];
        original_string[index] = temp_char;
    }
}


void PrintString(const string& my_string){
    for (auto current_char: my_string){
        cout << current_char << ' ';
    }
    cout << endl;
}