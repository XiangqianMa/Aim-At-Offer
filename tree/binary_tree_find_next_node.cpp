//
// Created by mxq on 20-1-7.
//

#include "binary_tree_find_next_node.h"
using BinaryTreeNode = find_next_node::BinaryTreeNode;


/*
 * 给出二叉树中的一个节点，求当对该二叉树进行中序遍历时，该节点的下一个节点
 */
BinaryTreeNode *GetNextNode(BinaryTreeNode *node)
{
    if (node == nullptr)
        return nullptr;

    BinaryTreeNode *next_node = nullptr;
    // 当右子树不为空时，返回其右子树的最左节点
    if (node->right_node != nullptr){
        next_node = node->right_node;
        while (next_node->left_node != nullptr)
            next_node = next_node->left_node;
        return next_node;
    }
    if (node->father_node != nullptr) {
        // 右子树为空，而节点为其父节点的左子节点时，返回其父节点
        if (node->father_node->left_node == node)
            return node;
        next_node = node->father_node;
        while (next_node != nullptr && next_node->father_node != nullptr) {
            if (next_node->father_node->left_node == next_node)
                return next_node;
            next_node = next_node->father_node;
        }
    }
    return nullptr;
}