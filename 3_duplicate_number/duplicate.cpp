//
// Created by mxq on 19-12-30.
//

/*
 * 找到数组中任意重复的数字
*/
#include "duplicate.h"


// 题目一
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


// 题目二
bool get_duplicate(vector<int> numbers, int &duplicate)
{
    if (numbers.empty())
        return false;
    for (auto number: numbers)
        if (number < 1 || number > numbers.size() - 1)
            return false;
    int start = 1;
    int end = static_cast<int>(numbers.size() - 1);
    int mid_number = (start + end) / 2;
    while (start <= end){
        int count = count_number(numbers, start, mid_number);
        if (start == end){
            // 当范围中的数字只是单个值时
            if (count > 1) {
                // 数目大于1，说明当前数字重复
                duplicate = start;
                return true;
            }
            else
                break; // 否则无重复数字
        }
        // 如果前半个范围的元素的数目大于中范围中数字不重复情况下的数字个数，则说明重复的数字位于前半个范围
        if (count > (mid_number - start) + 1)
            end = mid_number;
        else
            start = mid_number + 1; // 否则位于后半个范围
        mid_number = (start + end) / 2;
    }
    return false;
}


/*
 * 统计特定范围内的数字在数组中出现的次数
 */
int count_number(const vector<int> numbers, const int start, const int end)
{
    int count = 0;
    for (auto i: numbers){
        if (i >= start && i<= end)
            count++;
    }
    return count;
}