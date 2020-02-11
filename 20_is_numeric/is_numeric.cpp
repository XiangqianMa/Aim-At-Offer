//
// Created by mxq on 2020/2/11.
//

#include "is_numeric.h"


/**
 * @brief 判断一个字符串是否可以构成数字
 * @param str
 * @return
 */
bool IsNumeric(const string& str){
    int index = 0;
    bool numeric = ScanInteger(str, index);

    if (str[index] == '.'){
        index++;
        numeric = numeric || ScanUnsignedInteger(str, index);  // 小数点可以没有前面的数，也可以没有后面的数
    }

    if (str[index] == 'e' || str[index] == 'E'){
        index++;
        numeric = numeric && ScanInteger(str, index);  // e前后必须都满足
    }
    // 扫描完整个字符串
    return numeric && index == str.size();
}


/**
 * @brief 扫描可能以表示正负的'+'或者'-'为起始的0～9的数位
 * @param str 字符串
 * @param index 扫描起始位置索引
 * @return
 */
bool ScanInteger(const string& str, int& index){
    if (str[index] == '+' || str[index] == '-')
        index++;
    return ScanUnsignedInteger(str, index);
}


/**
 * @brief 扫描字符串中0~9的数位（类似于无符号整数）
 * @param str 字符串
 * @param index 扫描起始位置索引
 * @return
 */
bool ScanUnsignedInteger(const string& str, int& index){
    int start_index = index;
    while (str[index] >= '0' && str[index] <= '9' && index < str.size())
        index++;
    // 当index与start_index之间位于0～9之间的字符的个数大于0个时返回true
    return index > start_index;
}