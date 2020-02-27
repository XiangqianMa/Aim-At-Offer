//
// Created by mxq on 2020/2/27.
//

#include "is_balanced_binary_tree.h"


/**
 * @brief 判断二叉树是否是平衡二叉树
 * @param root
 * @return
 */
bool IsBalanced(BinaryTreeNode* root){
    if (root == nullptr)
        return false;
    int depth;
    return IsBalancedCore(root, depth);
}


/**
 * @brief 采用后续遍历的方式判断一棵二叉树是否是平衡二叉树
 * @param root
 * @param depth
 * @return
 */
bool IsBalancedCore(BinaryTreeNode* root, int& depth){
    if (root == nullptr){
        depth = 0;
        return true;
    }

    int left_depth, right_depth;
    bool is_balanced = false;
    if (IsBalancedCore(root->left_node, left_depth) && IsBalancedCore(root->right_node, right_depth)){
        int depth_diff = left_depth - right_depth;
        if (depth_diff >= -1 && depth_diff <= 1){
            depth = left_depth > right_depth? (left_depth + 1) : (right_depth + 1);
            is_balanced = true;
        }
    }
    return is_balanced;
}