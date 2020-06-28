//
// Created by mxq on 20-1-3.
//

#include "replace_black.h"


/*
 * 将字符串数组中的空格全部替换为"%20" ，要注意的是传入的字符串数组要保证有足够的空间容纳替换后的字符串
 * 输入参数：
 *      char 5_string[]: 字符串数组
 *      const int length: 字符串数组的长度
 */
bool replace_blank(char string[], int length)
{
    if (string == nullptr || length == 0)
        return false;
    int end_old = 0;
    while (string[end_old] != '\0'){
        end_old++;
    }
    // 计算替换了空格后，字符串最后一个字符的下标
    int end_new = end_old;
    for (int i=0; i <= end_old; i++){
        if (string[i] == ' ')
            end_new += 2;
    }

    if (end_new+1 > length)
        return false;
    // 进行字符串迁移
    while (end_old >= 0 && end_new > end_old){
        if (string[end_old] == ' '){
            string[end_new--] = '0';
            string[end_new--] = '2';
            string[end_new--] = '%';
        }else{
            string[end_new--] = string[end_old];
        }
        end_old--;
    }
    return end_new == end_old;
}