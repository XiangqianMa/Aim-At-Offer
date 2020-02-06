//
// Created by mxq on 2020/2/5.
//

#ifndef AIM_AT_OFFER_DELETE_LIST_NODE_H
#define AIM_AT_OFFER_DELETE_LIST_NODE_H

struct ListNode{
    int val;
    ListNode* next;
};

void DeleteNode(ListNode** list_head, ListNode* node_to_be_deleted);
#endif //AIM_AT_OFFER_DELETE_LIST_NODE_H
