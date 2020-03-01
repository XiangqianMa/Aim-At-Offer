//
// Created by mxq on 2020/3/1.
//

#include "last_number_in_circle.h"


/**
 * @brief 使用list模仿循环链表，完成按定长删除循环链表中的元素
 * @param data_number 循环链表的长度，链表中元素为[0, n-1]
 * @param m 间隔长度
 * @return
 */
int LastNumberInCircle(unsigned int data_number, unsigned int m){
    if (data_number <= 1 || m <= 0)
        return -1;

    // 初始化循环链表，使用单链表模仿循环链表
    list<int> circle_list;
    for (int i = 0; i < data_number; i++)
        circle_list.push_back(i);

    auto start_iter = circle_list.begin();
    while (circle_list.size() > 1){
        if (start_iter == circle_list.end())
            start_iter = circle_list.begin();
        // 沿着链表向前进m-1步
        for (int i = 0; i < m - 1; i++){
            start_iter++;
            if (start_iter == circle_list.end())
                start_iter = circle_list.begin();
        }
        start_iter = circle_list.erase(start_iter);
    }

    return circle_list.back();
}


/**
 * @brief 依据递归公式计算，f(n, m) =  0,                    n = 1
 *                                  [f(n - 1, m) + m] % n, n > 1
 *        该公式采用将各个移除元素后的序列映射为连续序列，得到删除的元素，再将删除的元素反映射回原来的区间的方式得到
 * @param n
 * @param m
 * @return
 */
int LastNumberInCircleSolution2(unsigned int n, unsigned int m){
    if (n <= 1 || m < 1)
        return -1;
    int last = 0;
    for (int i = 2; i <= n; i++){
        last = (last + m) % i;
    }
    return last;
}