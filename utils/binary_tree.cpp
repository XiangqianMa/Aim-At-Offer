//
// Created by 任芷颖 on 2020/2/17.
//

#include <cstdio>
#include "binary_tree.h"


/**
 * @brief 构建二叉树的一个节点
 * @param value
 * @return
 */
BinaryTreeNode* CreateBinaryTreeNode(int value)
{
    auto* pNode = new BinaryTreeNode();
    pNode->val = value;
    pNode->left_node = nullptr;
    pNode->right_node = nullptr;

    return pNode;
}


/**
 * @brief 将父节点与其左子节点和右子节点相连接
 * @param pParent
 * @param pLeft
 * @param pRight
 */
void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
    if(pParent != nullptr)
    {
        pParent->left_node = pLeft;
        pParent->right_node = pRight;
    }
}



void PrintTreeNode(const BinaryTreeNode* pNode)
{
    if(pNode != nullptr)
    {
        printf("value of this node is: %d\n", pNode->val);

        if(pNode->left_node != nullptr)
            printf("value of its left child is: %d.\n", pNode->left_node->val);
        else
            printf("left child is nullptr.\n");

        if(pNode->right_node != nullptr)
            printf("value of its right child is: %d.\n", pNode->right_node->val);
        else
            printf("right child is nullptr.\n");
    }
    else
    {
        printf("this node is nullptr.\n");
    }

    printf("\n");
}


/**
 * @brief 打印一棵二叉树
 * @param pRoot
 */
void PrintTree(const BinaryTreeNode* pRoot)
{
    PrintTreeNode(pRoot);

    if(pRoot != nullptr)
    {
        if(pRoot->left_node != nullptr)
            PrintTree(pRoot->left_node);

        if(pRoot->right_node != nullptr)
            PrintTree(pRoot->right_node);
    }
}


/**
 * @brief 销毁一棵二叉树
 * @param pRoot
 */
void DestroyTree(BinaryTreeNode* pRoot)
{
    if(pRoot != nullptr)
    {
        BinaryTreeNode* pLeft = pRoot->left_node;
        BinaryTreeNode* pRight = pRoot->right_node;

        delete pRoot;
        pRoot = nullptr;

        DestroyTree(pLeft);
        DestroyTree(pRight);
    }
}