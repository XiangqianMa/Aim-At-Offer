//
// Created by mxq on 2020/2/29.
//

#include "left_rotate_string.h"


/**
 * @brief 将字符串左旋k个字符
 * @param str
 * @param k
 */
void LeftRotateString(string& str, int k){
    if (str.empty() || k <= 0)
        return;
    Reverse(str.begin(), str.end() - 1);  // 反转整个句子
    Reverse(str.begin(), str.end() - 1 - k);  // 反转前一部分的字符
    Reverse(str.end() - k, str.end() - 1);  // 反转后k个字符
}