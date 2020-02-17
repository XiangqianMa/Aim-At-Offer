#include "include.h"

using namespace std;


int main() {
    BinaryTreeNode* root = CreateBinaryTreeNode(10);
    BinaryTreeNode* node1 = CreateBinaryTreeNode(5);
    BinaryTreeNode* node2 = CreateBinaryTreeNode(12);
    ConnectTreeNodes(root, node1, node2);
    BinaryTreeNode* node3 = CreateBinaryTreeNode(4);
    BinaryTreeNode* node4 = CreateBinaryTreeNode(7);
    ConnectTreeNodes(node1, node3, node4);
    FindPathInTree(root, 22);
}