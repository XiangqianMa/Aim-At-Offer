//
// Created by mxq on 2020/2/14.
//

#ifndef AIM_AT_OFFER_MERGE_TWO_SORTED_ARRAY_H
#define AIM_AT_OFFER_MERGE_TWO_SORTED_ARRAY_H


struct ListNode{
    int val;
    ListNode* next;
};

ListNode* MergeTwoSortedList(ListNode* list_head_a, ListNode* list_node_b);
ListNode* MergeTwoSortedListRecursive(ListNode* list_head_a, ListNode* list_head_b);
#endif //AIM_AT_OFFER_MERGE_TWO_SORTED_ARRAY_H
