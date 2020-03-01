//
// Created by mxq on 2020/3/1.
//

#include "dicies_probability.h"


/**
 * @brief 使用回溯法计算投骰子问题中所有可能的和的概率值
 * @param dices_number 骰子的个数
 * @param dice_max_value 骰子中的最大点数
 */
void PrintProbability(const int& dices_number, const int& dice_max_value){
    if (dices_number <= 0)
        return;
    // 存放每个sum出现的次数
    vector<int> sum_times(dice_max_value * dices_number - dices_number + 1, 0);
    // 使用回溯法统计每个可能的和出现的次数
    Probability(dices_number, sum_times, dice_max_value);
    int total_sum_times = pow(dice_max_value, dices_number);
    for (int sum_index = 0; sum_index < sum_times.size(); sum_index++){
        double probability = (double)(sum_times[sum_index]) / total_sum_times;
        int current_sum = dices_number + sum_index;
        cout << "Sum: " << current_sum << " Probability: " << probability << endl;
    }
}


/**
 * @brief 使用回溯法求解每个可能的和出现的次数
 * @param dices_number 骰子个数
 * @param sum_times 存储可能和的出现次数的数组
 * @param dice_max_value 骰子最大值
 */
void Probability(const int dices_number, vector<int>& sum_times, const int dice_max_value){
    for (int i = 1; i <= dice_max_value; i++){
        ProbabilityRecursiveCore(dices_number, dices_number, i, sum_times, dice_max_value);
    }
}


/**
 * @brief 递归实现的核心函数
 * @param min_sum 和的最小值（dices_number * 1）
 * @param current_dice 已处理到的骰子的编号
 * @param sum 已经得到的和
 * @param sum_times 存储可能和的出现次数的数组
 * @param dice_max_value 骰子的最大值
 */
void ProbabilityRecursiveCore(int min_sum, int current_dice, int sum, vector<int>& sum_times, const int dice_max_value){
    if (current_dice == 1){
        sum_times[sum - min_sum]++;
        cout << sum << endl;
    } else{
        // 处理第current_dice个骰子
        for (int i = 1; i <= dice_max_value; i++){
            ProbabilityRecursiveCore(min_sum, current_dice - 1, sum + i, sum_times, dice_max_value);
        }
    }
}