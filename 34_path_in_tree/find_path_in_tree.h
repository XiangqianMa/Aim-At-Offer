//
// Created by mxq on 2020/2/17.
//

#ifndef AIM_AT_OFFER_FIND_PATH_IN_TREE_H
#define AIM_AT_OFFER_FIND_PATH_IN_TREE_H

#include <vector>
#include <iostream>
#include "../utils/binary_tree.h"

using namespace std;

void PrintPath(const vector<BinaryTreeNode*>& path_stack);
void FindPathInTreeCore(BinaryTreeNode* root, int expected_sum, int current_sum, vector<BinaryTreeNode*> path_stack);
void FindPathInTree(BinaryTreeNode* root, int expected_sum);
#endif //AIM_AT_OFFER_FIND_PATH_IN_TREE_H
