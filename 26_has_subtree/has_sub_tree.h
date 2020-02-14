//
// Created by mxq on 2020/2/14.
//

#ifndef AIM_AT_OFFER_HAS_SUB_TREE_H
#define AIM_AT_OFFER_HAS_SUB_TREE_H


struct BinaryTreeNode {
    int val;
    BinaryTreeNode* left_node;
    BinaryTreeNode* right_node;
};

bool TreeAHasTreeB(BinaryTreeNode* root_a, BinaryTreeNode* root_b);
#endif //AIM_AT_OFFER_HAS_SUB_TREE_H
