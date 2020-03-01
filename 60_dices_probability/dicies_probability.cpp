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


/**
 * @brief 使用动态规划求解骰子之和问题，每一加入一个骰子，状态转移表表示当前可以达到的和所对应的次数
 * @param dices_number 骰子数目
 * @param dice_max_value 骰子点数的最大值
 */
void PrintProbabilityIterate(const int& dices_number, const int& dice_max_value){
    if (dices_number <= 0)
        return;
    // 状态转移表
    vector<vector<int>> sum_times_state(2, vector<int>(dice_max_value * dices_number + 1, 0));
    // 初始化起始状态
    for (int i = 1; i <= dice_max_value; i++)
        sum_times_state[0][i] = 1;
    int state_flag = 1;
    // 进行状态转移
    for (int dice_index = 2; dice_index <= dices_number; dice_index++){
        // 将小于dice_index的次数都置为0
        for (int i = 0; i < dice_index; i++)
            sum_times_state[state_flag][i] = 0;

        for (int sum_value = dice_index; sum_value <= dice_index * dice_max_value; sum_value++){
            sum_times_state[state_flag][sum_value] = 0;  // 将当前sum值对应的次数置0，重新计算
            for (int current_dice_value = 1; current_dice_value <= sum_value && current_dice_value <= dice_max_value;
                current_dice_value++){  // 取上次状态的sum_value - 1, sum_value - 2, sum_value - 3,... , sum_value - 6的次数之和
                sum_times_state[state_flag][sum_value] += sum_times_state[1 - state_flag][sum_value - current_dice_value];
            }
        }
        state_flag = 1 - state_flag;
    }

    double total = pow((double)(dice_max_value), dices_number);
    cout << total << endl;
    int sum_times = 0;
    for (int index = dices_number; index <= dice_max_value * dices_number; index++){
        double probability = sum_times_state[1 - state_flag][index] / total;
        sum_times += sum_times_state[1 - state_flag][index];
        cout << "Sum: " << index << " Probability: " << probability << endl;
    }
    cout << sum_times;
}