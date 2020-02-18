//
// Created by mxq on 2020/2/18.
//

#include "convert_binary_search_tree.h"


/**
 * @brief 将二叉查找树转换为有序的双向链表
 * @param root
 * @return
 */
BinaryTreeNode* ConvertBinarySearchTree(BinaryTreeNode* root){
    if (root == nullptr)
        return nullptr;
    BinaryTreeNode* last_node_in_list = nullptr;
    ConvertNode(root, &last_node_in_list);

    // 找到链表头
    BinaryTreeNode* list_head = root;
    while (list_head->left_node != nullptr && list_head != nullptr){
        list_head = list_head->left_node;
    }
    return list_head;
}


/**
 * @brief 递归转换二叉树为双向链表
 * @param root
 * @param last_node_in_list
 */
void ConvertNode(BinaryTreeNode* root, BinaryTreeNode** last_node_in_list){
    if (root == nullptr)
        return;

    BinaryTreeNode* current_node = root;
    if (current_node->left_node != nullptr)
        ConvertNode(current_node->left_node, last_node_in_list);
    current_node->left_node = *last_node_in_list;
    if (*last_node_in_list != nullptr)
        (*last_node_in_list)->right_node = current_node;
    *last_node_in_list = current_node;
    if (current_node->right_node != nullptr)
        ConvertNode(current_node->right_node, last_node_in_list);
}