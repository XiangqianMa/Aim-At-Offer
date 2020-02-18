//
// Created by mxq on 2020/2/18.
//

#ifndef AIM_AT_OFFER_CLONE_COMPLEX_LIST_H
#define AIM_AT_OFFER_CLONE_COMPLEX_LIST_H

struct ComplexListNode{
    int val;
    ComplexListNode* next;
    ComplexListNode* sibling;
};

void CloneNodes(ComplexListNode* list_head);
void ConnectSiblingNodes(ComplexListNode* list_head);
ComplexListNode* SplitNodes(ComplexListNode* list_head);
#endif //AIM_AT_OFFER_CLONE_COMPLEX_LIST_H
