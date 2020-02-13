//
// Created by mxq on 2020/2/13.
//

#ifndef AIM_AT_OFFER_FIND_KTH_TO_TAIL_H
#define AIM_AT_OFFER_FIND_KTH_TO_TAIL_H

#include <iostream>


struct ListNode{
    int val;
    ListNode* next;
};


ListNode* FindKthToTail(ListNode* list_head, unsigned int k);
#endif //AIM_AT_OFFER_FIND_KTH_TO_TAIL_H
