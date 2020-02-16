//
// Created by mxq on 2020/2/16.
//

#include "print_from_top_to_bottom.h"


/**
 * @brief 不分行从上到下按层打印二叉树
 * @param root
 * @return
 */
void PrintFromTopToBottom(BinaryTreeNode* root){
    if (root == nullptr)
        return;
    deque<BinaryTreeNode*> nodes_deque;
    nodes_deque.push_back(root);
    while (!nodes_deque.empty()){
        BinaryTreeNode* current_node = nodes_deque.front();
        cout << current_node->val;
        if (current_node->left_node != nullptr)
            nodes_deque.push_back(current_node->left_node);
        if (current_node->right_node != nullptr)
            nodes_deque.push_back(current_node->right_node);
        nodes_deque.pop_front();
    }
}


/**
 * @brief 分行从上到下打印二叉树
 * @param root
 */
void PrintFromTopToBottomFreshLine(BinaryTreeNode* root){
    if (root == nullptr)
        return;
    deque<BinaryTreeNode*> nodes_deque;
    nodes_deque.push_back(root);
    int to_be_printed_number = 1;
    int next_level_nodes_number = 0;
    while (!nodes_deque.empty()){
        BinaryTreeNode* current_node = nodes_deque.front();
        cout << current_node->val << endl;
        if (current_node->left_node){
            nodes_deque.push_back(current_node->left_node);
            next_level_nodes_number++;
        }

        if (current_node->right_node){
            nodes_deque.push_back(current_node->right_node);
            next_level_nodes_number++;
        }
        to_be_printed_number--;
        if (to_be_printed_number == 0){
            cout << endl;
            to_be_printed_number = next_level_nodes_number;
            next_level_nodes_number = 0;
        }
    }
}


/**
 * @brief 之字形打印二叉树，借助双栈实现
 * @param root
 */
void PrintTreeInZigZag(BinaryTreeNode* root){
    if (root == nullptr)
        return;
    stack<BinaryTreeNode*> left_to_right;
    stack<BinaryTreeNode*> right_to_left;
    left_to_right.push(root);

    while (!left_to_right.empty() || !right_to_left.empty()){
        // 打印从左到右的一行
        bool fresh_line = false;
        while (!left_to_right.empty()){
            BinaryTreeNode* current_node = left_to_right.top();
            cout << current_node->val;
            if (current_node->left_node)
                right_to_left.push(current_node->left_node);
            if (current_node->right_node)
                right_to_left.push(current_node->right_node);
            left_to_right.pop();
            fresh_line = true;
        }
        if (fresh_line)
            cout << endl;

        fresh_line = false;
        // 打印从右到左的一行
        while (!right_to_left.empty()){
            BinaryTreeNode* current_node = right_to_left.top();
            cout << current_node->val;
            if (current_node->right_node)
                left_to_right.push(current_node->right_node);
            if (current_node->left_node)
                left_to_right.push(current_node->left_node);
            fresh_line = true;
        }
        if (fresh_line)
            cout << endl;
    }
}