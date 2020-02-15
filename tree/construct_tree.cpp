//
// Created by mxq on 20-1-6.
// 使用递归的方式实现从 先序遍历序列 和 中序遍历序列中恢复二叉树
//

#include "construct_tree.h"


BinaryTreeNode *ConstructTree(vector<int> preorder, vector<int> inorder)
{
    if (preorder.empty() || inorder.empty())
        return nullptr;
    return ConstructTreeCore(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
}


BinaryTreeNode *ConstructTreeCore(
        vector<int>::iterator preorder_start,
        vector<int>::iterator preorder_end,
        vector<int>::iterator inorder_start,
        vector<int>::iterator inorder_end
        )
{
    int root_value = *preorder_start;
    auto *root = new BinaryTreeNode;
    root->val = root_value;
    root->left_node = root->right_node = nullptr;

    // 序列中只剩余一个元素的情况
    if (preorder_start == preorder_end - 1){
        // 中序遍历序列同样只剩余一个元素，且该元素与前序遍历的元素相同
        if (inorder_start == inorder_end - 1 && *preorder_start == *inorder_start)
            return root;
        else
            throw "Invalid Input.";
    }

    // 在中序遍历序列中找到根节点的位置
    auto root_node_iter = inorder_start;
    while (*root_node_iter != root_value && root_node_iter != inorder_end){
        root_node_iter++;
    }
    if (*root_node_iter != root_value && root_node_iter == inorder_end)
        throw "Invalid Input.";

    // 递归构建左子树
    auto left_preorder_start = preorder_start + 1;
    auto left_preorder_end = preorder_start + (root_node_iter - inorder_start) + 1;
    auto left_inorder_start = inorder_start;
    auto left_inorder_end = root_node_iter;
    // 左子树的节点数不为空
    if (root_node_iter - inorder_start > 0){
        root->left_node = ConstructTreeCore(left_preorder_start, left_preorder_end,
                left_inorder_start, left_inorder_end);
    }

    // 递归构建右子树
    auto right_preorder_start = preorder_start + (root_node_iter - inorder_start) +1;
    auto right_preorder_end = preorder_end;
    auto right_inorder_start = root_node_iter + 1;
    auto right_inorder_end = inorder_end;
    // 右子树的节点不为空
    if (inorder_end - root_node_iter > 1){
        root->right_node = ConstructTreeCore(right_preorder_start, right_preorder_end,
                right_inorder_start, right_inorder_end);
    }

    return root;
}