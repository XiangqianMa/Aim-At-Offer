//
// Created by mxq on 20-1-2.
//

#include "find_number_in_matrix.h"


/*
 * 在二维数组中查找是否存在特定的元素，该数组中的元素有以下特点：
 * 每一行的元素，从左到右依次递增；每一列的元素，从上到下依次递增。
 * 本代码使用的是从右上角向左下角查找的方式
 */
bool find_number(vector<vector<int>> matrix, int height, int width, int number)
{
    int x = 0;
    int y = width - 1;
    bool found = false;

    if (!matrix.empty() || height > 0 || width > 0) {
        while (x <= height - 1 && y >= 0) {
            if (number == matrix[x][y]) {
                found = true;
                break;
            }
            // 只剩余最后一个元素，且不相等，则不存在
            if (x == height - 1 && y == 0) {
                found = false;
                break;
            }
            if (number > matrix[x][y])
                // 剔除当前行
                x++;
            else
                // 剔除当前列
                y--;
        }
    }
    return found;
}