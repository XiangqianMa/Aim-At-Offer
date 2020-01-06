//
// Created by mxq on 20-1-6.
//

#ifndef AIM_AT_OFFER_CONSTRUCT_TREE_H
#define AIM_AT_OFFER_CONSTRUCT_TREE_H

#include <iostream>
#include <vector>

using namespace std;

struct BinaryTreeNode
{
    int node_value;
    BinaryTreeNode *left_node;
    BinaryTreeNode *right_node;
};

BinaryTreeNode *ConstructTree(vector<int> preorder, vector<int> inorder);
BinaryTreeNode *ConstructTreeCore(
        vector<int>::iterator preorder_start,
        vector<int>::iterator preorder_end,
        vector<int>::iterator inorder_start,
        vector<int>::iterator inorder_end
);
#endif //AIM_AT_OFFER_CONSTRUCT_TREE_H
