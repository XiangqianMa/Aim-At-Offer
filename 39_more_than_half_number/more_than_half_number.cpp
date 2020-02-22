//
// Created by mxq on 2020/2/21.
//

#include "more_than_half_number.h"

/**
 * @brief 使用找出中位数元素的方式找出个数超过一半的元素，借助快排的Partition函数实现
 * @param numbers
 * @return
 */
int MoreThanHalfNumber(vector<int>& numbers){
    if (numbers.empty())
        return 0;
    int start = 0;
    int end = numbers.size() - 1;
    int index = Partition(numbers, start, end);
    int middle_index = numbers.size() >> 1;
    while (index != middle_index) {
        if (index > middle_index){
            end = index - 1;
            index = Partition(numbers, start, end);
        }
        else {
            start = index + 1;
            index = Partition(numbers, start, end);
        }
    }

    int result = numbers[index];
    if (!CheckMoreThanHalf(numbers, numbers[index]))
        result = 0;
    return result;
}


/**
 * @brief 个数超过一半的元素的个数肯定比其他所有元素的个数都多
 * @param numbers
 * @return
 */
int MoreThanHalfNumberCount(const vector<int>& numbers){
    if (numbers.empty())
        return 0;

    int result = numbers[0];
    int times = 1;
    for (auto number: numbers){
        if (times == 0){
            result = number;
            times = 1;
        }
        else if (number == result) {
            times++;
        }
        else {
           times--;
        }
    }
    if (!CheckMoreThanHalf(numbers, result))
        result = 0;
    return result;
}


/**
 * @param 上面两种方法都是必要非充分条件，需要使用本函数进行最终的判断
 * @param numbers
 * @param number
 * @return
 */
bool CheckMoreThanHalf(const vector<int>& numbers, int& number){
    int count = 0;
    for (auto temp_number: numbers){
        if (temp_number == number)
            count++;
    }
    return count * 2 > numbers.size();
}


/**
 * @brief 随机从数组中选择元素，将数组划分为左侧都小于该元素，右侧都大于该元素的形式
 * @param numbers 数组
 * @param start 起始位置下标
 * @param end 终止位置下标
 * @return
 */
int Partition(vector<int>& numbers, int start, int end){
    if (numbers.empty() || start < 0 || end > numbers.size() - 1)
        throw "Invalid Parameters";
    unsigned int selected_index = RandomInRange(start, end);

    swap(numbers[end], numbers[selected_index]);  // 将选中的数交换到序列的末尾
    int small_index = start - 1; // 该下标之前的所有元素都小于等于选中的数
    for (int index = start; index <= end - 1; index++){
        if (numbers[index] < numbers[end]){
            small_index++;
            if (small_index != index){
                swap(numbers[small_index], numbers[index]);
            }
        }
    }
    // 将被选中的元素放到正确的位置（左侧元素小，右侧元素大）
    swap(numbers[small_index + 1], numbers[end]);
    return small_index + 1;
}


unsigned int RandomInRange(unsigned int start, unsigned int end){
    return rand() % (end - start + 1) + start;
}