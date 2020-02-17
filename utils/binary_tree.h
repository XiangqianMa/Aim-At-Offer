//
// Created by mxq on 2020/2/17.
//

#ifndef AIM_AT_OFFER_BINARY_TREE_H
#define AIM_AT_OFFER_BINARY_TREE_H

struct BinaryTreeNode{
    int val;
    BinaryTreeNode* left_node;
    BinaryTreeNode* right_node;
};

BinaryTreeNode* CreateBinaryTreeNode(int value);
void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight);
void PrintTreeNode(const BinaryTreeNode* pNode);
void PrintTree(const BinaryTreeNode* pRoot);
void DestroyTree(BinaryTreeNode* pRoot);
#endif //AIM_AT_OFFER_BINARY_TREE_H
