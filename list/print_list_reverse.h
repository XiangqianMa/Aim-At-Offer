//
// Created by mxq on 20-1-4.
//

#ifndef AIM_AT_OFFER_PRINT_LIST_REVERSE_H
#define AIM_AT_OFFER_PRINT_LIST_REVERSE_H

#include <stack>
#include <iostream>

using namespace std;

struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};

void add_to_tail(ListNode **list_head, int value);
void print_list_reverse_iterative(ListNode *list_head);
void print_list_reverse_recursive(ListNode *list_head);

#endif //AIM_AT_OFFER_PRINT_LIST_REVERSE_H
