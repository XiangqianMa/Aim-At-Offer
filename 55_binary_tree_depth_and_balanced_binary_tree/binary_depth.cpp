//
// Created by mxq on 2020/2/27.
//

#include "binary_depth.h"


/**
 * @brief 计算二叉树的深度
 * @param root
 * @return
 */
int GetBinaryTreeDepth(BinaryTreeNode* root){
    if (root == nullptr)
        return 0;
    int left_depth = GetBinaryTreeDepth(root->left_node);
    int right_depth = GetBinaryTreeDepth(root->right_node);

    return left_depth > right_depth? (left_depth + 1): (right_depth + 1);
}