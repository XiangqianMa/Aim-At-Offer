//
// Created by mxq on 2020/2/14.
//

#include "mirror_tree.h"


/**
 * @brief 得到一颗二叉树的镜像树
 * @param root
 */
void MirrorTree(BinaryTreeNode* root){
    if (root == nullptr)
        return;
    if (root->left_node == nullptr && root->right_node == nullptr)
        return;

    BinaryTreeNode* temp_node = root->right_node;
    root->right_node = root->left_node;
    root->left_node = temp_node;

    MirrorTree(root->left_node);
    MirrorTree(root->right_node);
}