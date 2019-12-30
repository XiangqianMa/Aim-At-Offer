//
// Created by mxq on 19-12-30.
//

/*
 * 找到数组中任意重复的数字
*/
#include "duplicate.h"


bool duplicate(vector<int> numbers, int &duplicate)
{
    // 不符合要求的异常情况
    if (numbers.empty())
        return false;
    for (auto i: numbers){
        if (i < 0 || i > numbers.size()-1)
            return false;
    }
    int index = 0;
    while (index < numbers.size()){
        int current_number = numbers[index];
        if (current_number != index){
            // 当前位置处的值和索引值不相等
            if (current_number == numbers[current_number]){
                // 如果当前值对应的位置的值和当前值相等，则说明找到重复的元素
                duplicate = current_number;
                return true;
            }else{
                // 否则，将两个位置的值交换
                int temp = numbers[current_number];
                numbers[current_number] = current_number;
                numbers[index] = temp;
            }
        }else
            // 否则，继续检查下一个位置处的元素
            index++;
    }
    return false;
}
