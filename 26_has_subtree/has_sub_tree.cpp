//
// Created by mxq on 2020/2/14.
//

#include "has_sub_tree.h"


/**
 * @brief 判断二叉树root_a中是否包含二叉树root_b
 * @param root_a
 * @param root_b
 * @return
 */
bool HasSubTree(BinaryTreeNode* root_a, BinaryTreeNode* root_b){
    if (root_a == nullptr || root_b == nullptr)
        return false;

    bool result;
    // 如果a当前根节点的值和b的根节点相等，则考察当前a根节点对应的子树是否与b匹配
    if (root_a->val == root_b->val)
        result = TreeAHasTreeB(root_a, root_b);
    else // 否则递归考察左子树和右子树
        result = HasSubTree(root_a->left_node, root_b) || HasSubTree(root_a->right_node, root_b);
    return result;
}


/**
 * @brief 判断root_a和root_b对应的两棵二叉树的结构是否匹配
 * @param root_a
 * @param root_b
 * @return
 */
bool TreeAHasTreeB(BinaryTreeNode* root_a, BinaryTreeNode* root_b){
    // tree_b遍历完，则返回true
    if (root_b == nullptr)
        return true;
    // tree_b没遍历完，但tree_a遍历完则返回false
    if (root_a == nullptr)
        return false;

    // 左右子节点有一个不匹配，则返回false
    if (root_a->left_node->val != root_b->left_node->val || root_a->right_node->val != root_b->right_node->val)
        return false;
    // 递归考察左子树和右子树
    return TreeAHasTreeB(root_a->left_node, root_b->left_node) && TreeAHasTreeB(root_a->right_node, root_b->right_node);
}