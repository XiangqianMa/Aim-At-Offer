//
// Created by mxq on 20-1-13.
//

#include "robot_attend_aray.h"


/*
 * @brief: 使用回溯法计算机器人所能到达的格子的个数
 */
int RobotMovingCount(int threshold, int rows, int cols)
{
    if (threshold <=0 || rows <=0 || cols <= 0)
        return 0;

    bool *visited = new bool[rows * cols];
    for (int i=0; i<rows*cols; i++)
        visited[i] = false;
    int count = RobotMovingCountCore(threshold, rows, cols, 0, 0, visited);
    delete[] visited;
    return count;
}


int RobotMovingCountCore(int threshold, int rows, int cols, int row, int col, bool *visited)
{
    int count = 0;
    if (CheckArrived(rows, cols, row, col, threshold, visited)){
        count += 1;
        visited[row * cols + col] = true;
        count += RobotMovingCountCore(threshold, rows, cols, row+1, col, visited)
                + RobotMovingCountCore(threshold, rows, cols, row-1, col, visited)
                + RobotMovingCountCore(threshold, rows, cols, row, col+1, visited)
                + RobotMovingCountCore(threshold, rows, cols, row, col-1, visited);
    }
    return count;
}


/*
 * @brief: 检查某个格子是否可以到达
 */
bool CheckArrived(int rows, int cols, int row, int col, int threshold, bool *visited)
{
    return row >= 0 && row < rows && col >= 0 && col < cols && GetDigitSum(row) + GetDigitSum(col) <= threshold
            && !visited[row * cols + col];
}


/*
 * @brief: 计算number的数位之和
 */
int GetDigitSum(int number)
{
    int sum = 0;
    while (number > 0)
    {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}