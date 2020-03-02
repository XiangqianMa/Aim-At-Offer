//
// Created by mxq on 20-1-9.
//

#include "fibonacci.h"


/*
 * 使用递归方式实现，时间复杂度过高，随着n的增大呈指数增长
 */
long long FibonacciRecrusive(unsigned int n){
    if (n <= 0)
        return 0;
    if (n == 1)
        return 1;

    return FibonacciRecrusive(n-1) + FibonacciRecrusive(n-2);
}


/*
 * 使用循环的方式实现，时间复杂度为O(n), 从小到大求解
 */
long long FibonacciIterative(unsigned int n){
    int result[2] = {0, 1};
    if (n <= 1)
        return result[n];

    long long fibnacci_n_minus_one = 1;
    long long fibnacci_n_minus_two = 0;
    long long fibnacci_n = 0;
    for (int i=2; i<=n; i++){
        fibnacci_n = fibnacci_n_minus_two + fibnacci_n_minus_one;
        fibnacci_n_minus_one = fibnacci_n_minus_two;
        fibnacci_n_minus_two = fibnacci_n;
    }
    return fibnacci_n;
}


/*
 * 使用小矩形填充大矩形 P79
 */
long long FillRectangle(int n){
    int result[2] = {1, 2};
    if (n <= 1)
        return result[n];

    long long fill_n_minus_one = 2;
    long long fill_n_minus_two = 1;
    long long fill_n = 0;
    for (int i=3; i<=n; i++){
        fill_n = fill_n_minus_one + fill_n_minus_two;
        fill_n_minus_one = fill_n_minus_two;
        fill_n_minus_two = fill_n;
    }
    return fill_n;
}