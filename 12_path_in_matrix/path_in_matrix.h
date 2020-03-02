//
// Created by mxq on 20-1-12.
//

#ifndef AIM_AT_OFFER_PATH_IN_ARRAY_H
#define AIM_AT_OFFER_PATH_IN_ARRAY_H

using namespace std;

#include <iostream>
#include <vector>
#include <memory>
#include <cstring>


template <typename T>
bool HasPath(T *matrix, int rows, int cols, T *path, int path_length);
template <typename T>
bool HasPathCore(T *matrix, int rows, int cols, int row, int col, T *path, int path_length, int &path_index, bool *visited);


/*
 * @brief: 使用回溯法查看矩阵中是否存在某一路径
 * @param: matrix: 矩阵
 * @param: rows: 矩阵的行数
 * @param: cols: 矩阵的列数
 * @param: path: 路径
 * @param: path_length: 路径的长度
 */
template <typename T>
bool HasPath(T *matrix, int rows, int cols, T *path, int path_length)
{
    // 异常情况检测
    if (matrix==nullptr ||rows==0 || cols==0 || path == nullptr || path_length == 0)
        return false;
    // 记录对应的节点是否被访问过
    bool *visited = new bool[rows * cols];
    memset(visited, 0, rows*cols);

    int path_index = 0;
    for (int row_index=0; row_index<rows; row_index++){
        for (int col_index=0; col_index<cols; col_index++){
            if (HasPathCore(matrix, rows, cols, row_index, col_index, path, path_length, path_index, visited)){
                return true;
            }
        }
    }
    delete[] visited;
    return false;
}


/*
 * @brief: 判断指定的节点及其后续节点时候能构成路径
 * @param: matrix: 待查找矩阵
 * @param: rows: 矩阵的行数
 * @param: cols: 矩阵的列数
 * @param: row: 当前元素的行坐标
 * @param: col: 当前元素的列坐标
 * @param: path: 路径序列
 * @param: path_length: 路径的长度
 * @param: path_index: 当前访问的路径的元素的下标
 * @param: visited: 记录对应元素是否被访问过的标记
 * @return: has_path: 标记是否包含路径
 */
template <typename T>
bool HasPathCore(T *matrix, int rows, int cols, int row, int col, T *path, int path_length, int &path_index, bool *visited)
{
    // 当遍历完整个路径时，返回true
    if (path_index == path_length)
        return true;
    bool has_path = false;
    // 查看当前节点是否满足要求
    if (row >= 0 && row < rows && col >= 0 && col < cols
        && matrix[row * cols + col] == path[path_index] && !visited[row * cols + col]){
        path_index++;
        visited[row * cols + col] = true;
        // 探索四个方向
        has_path = HasPathCore(matrix, rows, cols, row+1, col, path, path_length, path_index, visited)
                   || HasPathCore(matrix, rows, cols, row-1, col, path, path_length, path_index, visited)
                   || HasPathCore(matrix, rows, cols, row, col+1, path, path_length, path_index, visited)
                   || HasPathCore(matrix, rows, cols, row, col-1, path, path_length, path_index, visited);
        if (!has_path){
            path_index--;
            visited[row * cols + col] = false;
        }
    }
    return has_path;
}

#endif //AIM_AT_OFFER_PATH_IN_ARRAY_H
