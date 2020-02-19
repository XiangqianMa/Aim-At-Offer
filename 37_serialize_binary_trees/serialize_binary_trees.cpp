//
// Created by mxq on 2020/2/19.
//

#include "serialize_binary_trees.h"


/**
 * @brief 将二叉树序列化为前序遍历序列
 * @param root
 * @param stream
 */
void SerializeBinaryTree(BinaryTreeNode* root, ostream& stream){
    if (root == nullptr){
        stream << "$,";
        return;
    }

    stream << root->val << ',';
    SerializeBinaryTree(root->left_node, stream);
    SerializeBinaryTree(root->right_node, stream);
}


/**
 * @brief 将前序遍历序列反序列化为二叉树
 * @param root
 * @param stream
 */
void Deserialize(BinaryTreeNode** root, istream& stream){
    int number;
    if (ReadStream(stream, number)){
        *root = new BinaryTreeNode;
        (*root)->val = number;
        (*root)->left_node = nullptr;
        (*root)->right_node = nullptr;
        // 递归反序列化左子节点和右子节点
        Deserialize(&((*root)->left_node), stream);
        Deserialize(&((*root)->right_node), stream);
    }
}


bool ReadStream(istream& stream, int& number){
    string temp;
    stream >> temp;
    if (temp[0] == '$')
        return false;
    number = static_cast<int>(temp[0]);
    return true;
}