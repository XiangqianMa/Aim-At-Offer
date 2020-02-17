//
// Created by mxq on 2020/2/17.
//

#include "find_path_in_tree.h"

/**
 * @brief 输入一棵二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径
 * @param root 二叉树的根节点
 * @param expected_sum 期望的和
 */
void FindPathInTree(BinaryTreeNode* root, int expected_sum){
    if (root == nullptr)
        return;
    vector<BinaryTreeNode*> path_stack;
    FindPathInTreeCore(root, expected_sum, 0, path_stack);
}


/**
 * @brief 使用回溯法实现路径和判定
 * @param root 当前访问到的子树的根节点
 * @param expected_sum 期望的和
 * @param current_sum 已访问的路径中累计的和
 * @param path_stack 已访问的路径（使用vector模拟栈）
 */
void FindPathInTreeCore(BinaryTreeNode* root, int expected_sum, int current_sum, vector<BinaryTreeNode*> path_stack){
    current_sum += root->val;
    path_stack.push_back(root);

    // 如果当前节点是叶子节点，则判断路径中的值之和是否等于期望和
    bool is_leaf = root->left_node == nullptr && root->right_node == nullptr;
    if (is_leaf){
        if (current_sum == expected_sum)
            PrintPath(path_stack);
        return;
    }
    // 递归访问左子树和右子树
    if (root->left_node != nullptr)
        FindPathInTreeCore(root->left_node, expected_sum, current_sum, path_stack);
    if (root->right_node != nullptr)
        FindPathInTreeCore(root->right_node, expected_sum, current_sum, path_stack);
}


void PrintPath(const vector<BinaryTreeNode*>& path_stack){
    cout << "Find Path: ";
    for (auto node: path_stack)
        cout << node->val << ' ';
    cout << endl;
}
