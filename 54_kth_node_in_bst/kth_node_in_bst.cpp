//
// Created by mxq on 2020/2/27.
//

#include "kth_node_in_bst.h"


/**
 * @brief 查找二叉查找树中的第k大节点
 * @param root
 * @param k
 * @return
 */
BinaryTreeNode* FindKthNodeInBst(BinaryTreeNode* root, int k){
    if (root == nullptr || k <= 0)
        return nullptr;
    return FindKthNodeInBstCore(root, k);
}


/**
 * @brief 中序遍历
 * @param root
 * @param k
 * @return
 */
BinaryTreeNode* FindKthNodeInBstCore(BinaryTreeNode* root, int& k){
    BinaryTreeNode* target = nullptr;

    if (root->left_node != nullptr)
        target = FindKthNodeInBstCore(root->left_node, k);

    if (target == nullptr){
        if (k == 1)
            target = root;
        k--;
    }

    if (target == nullptr && root->right_node != nullptr)
        target = FindKthNodeInBstCore(root->right_node, k);
    return target;
}