//
// Created by mxq on 2020/2/28.
//

#include "number_appear_once.h"


/**
 * @brief 找出只出现一次的数字
 * @param numbers
 * @return
 */
int FindNumberAppearingOnce(const vector<int>& numbers){
    if (numbers.empty())
        throw "Empty numbers";

    // 将所有数对应的二进制位加起来
    vector<int> bit_sum(32, 0);
    for (auto number: numbers){
        int bit_mask = 1;
        for (int i = 31; i >= 0; i--){
            int bit = number & bit_mask;
            if (bit != 0)  // 当前位不为0
                bit_sum[i]++;
            bit_mask = bit_mask << 1;
        }
    }

    // 将不被3整出的bit向左移入result中
    int result = 0;
    for (int i = 0; i < 32; i++){
        result = result << 1;
        result += bit_sum[i] % 3;
    }
    return result;
}