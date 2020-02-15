//
// Created by mxq on 2020/2/15.
//

#include "print_matrix_clockwisely.h"


/**
 * @brief 按照从外到里以顺时针的顺序依次打印出每一个数字
 * @param numbers
 * @param columns 
 * @param rows
 */
void PrintMatrixClockwisely(int** numbers, int columns, int rows){
    if (numbers == nullptr || columns <=0 || rows <= 0)
        return;
    int start = 0;
    while (columns > 2 * start && rows > 2 * start){
        PrintMatrixInCircle(numbers, columns, rows, start);
        start++;
    }
}


void PrintMatrixInCircle(int** numbers, int columns, int rows, int start){
    int end_column = columns - start -1;
    int end_row = rows - start - 1;

    // 从左到右打印一行
    for (int j = start; j <= end_row; j++)
        std::cout << numbers[start][j] << std::endl;

    // 从上到下打印一列
    if (end_column - start >= 1){
        for (int i = start + 1; i <= end_column; i++)
            std::cout << numbers[i][end_row] << std::endl;
    }

    // 从右到左打印一行
    if (end_row - start >= 1 && end_column - start >= 1){
        for (int j = end_row - 1; j >= start; j--)
            std::cout << numbers[end_column][j] << std::endl;
    }

    // 从下到上打印一列
    if (end_column - start >= 2 && end_row - start >= 1){
        for (int i = end_column - 1; i > start; i--)
            std::cout << numbers[i][start] << std::endl;
    }
}