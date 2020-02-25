//
// Created by mxq on 2020/2/25.
//

#include "max_value_of_gifts.h"


/**
 * @brief 使用动态规划的思路求解所有路径中包含的最大礼物价值，使用二维状态转移表
 * @param gifts
 * @param rows
 * @param columns
 * @return
 */
int GetMaxValueOfGiftsSolution1(const vector<vector<int>>& gifts, const int& rows, const int& columns){
    if (gifts.empty() || rows <= 0 || columns <= 0)
        return 0;

    vector<vector<int>> values(rows, vector<int>(columns, 0));
    // 初始化第一行
    for (int i = 0; i < columns; i++){
        if (i == 0)
            values[0][i] = gifts[0][0];
        else
            values[0][i] = gifts[0][i] + values[0][i - 1];
    }

    for (int row_index = 1; row_index < rows; row_index++){
        for (int column_index = 0; column_index < columns; column_index++){
            int from_left = 0;
            if (column_index - 1 >= 0)
                from_left = values[row_index][column_index - 1] + gifts[row_index][column_index];

            int from_up = values[row_index - 1][column_index] + gifts[row_index][column_index];

            if (from_left > from_up)
                values[row_index][column_index] = from_left;
            else
                values[row_index][column_index] = from_up;
        }
    }
    return values[rows - 1][columns - 1];
}


/**
 * @brief 使用动态规划的思路求解所有路径中包含的最大礼物价值，使用一维状态转移表
 * @param gifts
 * @param rows
 * @param columns
 * @return
 */
int GetMaxValueOfGiftsSolution2(const vector<vector<int>>& gifts, const int& rows, const int& columns){
    vector<int> values(columns, 0);

    for (int i = 0; i < columns; i++){
        if (i == 0)
            values[i] = gifts[0][0];
        else
            values[i] = values[i - 1] + gifts[0][i];
    }

    for (int row_index = 1; row_index < rows; row_index++){
        for (int column_index = 0; column_index < columns; column_index++){
            int from_left = 0;
            if (column_index - 1 >= 0)
                from_left = values[column_index - 1] + gifts[row_index][column_index];
            int from_up = values[column_index] + gifts[row_index][column_index];
            values[column_index] = from_left > from_up? from_left: from_up;
        }
    }
    return values[columns - 1];
}