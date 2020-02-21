//
// Created by mxq on 20-1-11.
//
#include "find_min_in_roate_array.h"


/*
 * @brief 查找旋转数组中的最小值
 * @param roate_array: 旋转数组，该矩阵为将一个有序（从小到大）排列的数组的前面几个元素整体旋转到数组的后面得到
 */
int FindMinInRoateArray(vector<int> roate_array)
{
    if (roate_array.empty())
        throw "Empty array";
    unsigned long start_index = 0;
    unsigned long end_index = roate_array.size() - 1;
    unsigned long mid_index = start_index;
    while (roate_array[start_index] >= roate_array[end_index]){
        if (end_index - start_index == 1){
            mid_index = end_index;
            break;
        }

        // 当中间位置的元素和起始区间端点的元素相等时，无法确定中间元素属于哪一个递增区间，因而只能遍历
        if (roate_array[mid_index] == roate_array[start_index] && roate_array[mid_index] == roate_array[end_index]){
            return MinInArray(roate_array, start_index, end_index);
        }
        // 如果中间位置的值大于开始位置的值
        if (roate_array[mid_index] >= roate_array[start_index]){
            start_index = mid_index;
        } else if (roate_array[mid_index] <= roate_array[end_index]){
            end_index = mid_index;
        }
        mid_index = (start_index + end_index) >> 1;
    }
    return roate_array[mid_index];
}


/*
 * @brief 查找数组某个范围中的最小值
 * @param array: 待查找数组
 * @param start_index: 区间起始端点
 * @param end_index: 区间终止端点
 * @return min: 最小值
 */
int MinInArray(vector<int> array, unsigned long start_index, unsigned long end_index)
{
    int min = array[start_index];
    for (auto index=start_index+1; index<=end_index; index++){
        if (array[index] < min)
            min = array[index];
    }
    return min;
}
