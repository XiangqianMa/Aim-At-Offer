//
// Created by mxq on 2020/2/17.
//

#include "verify_post_sequence_of_bst.h"


/**
 * @brief 判断给定的后序遍历序列属于某个二叉查找树
 * @param sequence
 * @return
 */
bool VerifySequenceOfBst(vector<int> sequence){
    if (sequence.empty())
        return false;
    return VerifySequenceOfBstCore(sequence.begin(), sequence.end() - 1);
}


bool VerifySequenceOfBstCore(vector<int>::iterator first, vector<int>::iterator last){
    // 序列中只剩余一个元素
    if (first == last)
        return true;
    auto right_start = first;
    // 找到第一个比根节点值大的节点
    while (*right_start < *last){
        right_start++;
    }

    auto temp_iter = right_start;
    // 判断右侧序列是否存在比根节点小的元素
    while (temp_iter != last){
        if (*temp_iter < *last)
            return false;
        temp_iter++;
    }

    bool left_result = true;
    if (right_start - 1 - first >= 0)
        left_result = VerifySequenceOfBstCore(first, right_start - 1);

    bool right_result = true;
    if (last - 1 - right_start >= 0)
        right_result = VerifySequenceOfBstCore(right_start, last - 1);
    return left_result && right_result;
}
