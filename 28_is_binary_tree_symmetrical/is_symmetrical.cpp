//
// Created by mxq on 2020/2/15.
//

#include "is_symmetrical.h"


/**
 * @brief 判断一颗二叉树是否是对称二叉树，对比该二叉树的前序遍历序列和对称前序遍历序列是否相等
 * @param root
 * @return
 */
bool IsSymmetrical(BinaryTreeNode* root){
    return IsSymmetricalCore(root, root);
}


bool IsSymmetricalCore(BinaryTreeNode* root_a, BinaryTreeNode* root_b){
    if (root_a == nullptr && root_b == nullptr)
        return true;
    if (root_a == nullptr || root_b == nullptr)
        return false;

    if (root_a->val != root_b->val)
        return false;
    return IsSymmetricalCore(root_a->left_node, root_b->right_node)
        && IsSymmetricalCore(root_a->right_node, root_b->left_node);
}