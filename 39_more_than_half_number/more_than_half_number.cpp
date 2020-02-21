//
// Created by mxq on 2020/2/21.
//

#include "more_than_half_number.h"


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


bool CheckMoreThanHalf(const vector<int>& numbers, int& number){
    int count = 0;
    for (auto temp_number: numbers){
        if (temp_number == number)
            count++;
    }
    return count * 2 > numbers.size();
}


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