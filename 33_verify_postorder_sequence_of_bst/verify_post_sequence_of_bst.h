//
// Created by mxq on 2020/2/17.
//

#ifndef AIM_AT_OFFER_VERIFY_POST_SEQUENCE_OF_BST_H
#define AIM_AT_OFFER_VERIFY_POST_SEQUENCE_OF_BST_H

#include <vector>
#include <iostream>
#include "../utils/binary_tree.h"

using namespace std;

bool VerifySequenceOfBst(vector<int> sequence);
bool VerifySequenceOfBstCore(vector<int>::iterator first, vector<int>::iterator last);
#endif //AIM_AT_OFFER_VERIFY_POST_SEQUENCE_OF_BST_H
