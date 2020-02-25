//
// Created by mxq on 2020/2/25.
//

#include "longest_substring_without_duplication.h"


/**
 * @brief 求字符串中的最长无重复字符子串的长度
 * @param str
 * @return
 */
int LongestSubstringWithoutDuplication(const string& str){
    int current_length = 0;
    int max_length = 0;
    vector<int> position(26, -1);  // 每个字符上次出现的下标

    for (int i = 0; i < str.size(); i++){
        int previous_index = position[str[i] - 'a'];
        // 当前字符在之前未重复 或 与之前重复的字符的距离大于以前一个字符结尾的最长子串长度
        if (previous_index < 0 || i - previous_index > current_length)
            current_length++;
        else{  // 重复且距离小于以前一个字符结尾的最长子串长度
            if (current_length > max_length)
                max_length = current_length;
            current_length = i - previous_index;
        }
        position[str[i] - 'a'] = i;
    }
    if (current_length > max_length)
        max_length = current_length;
    return max_length;
}