//
// Created by mxq on 2020/2/26.
//

#include "first_common_node_in_lists.h"


ListNode* FindFirstCommonNodeInLists(ListNode* list_head_1, ListNode* list_head_2){
    int list_length_1 = CountListsNodes(list_head_1);
    int list_length_2 = CountListsNodes(list_head_2);

    // 提前将更长的链表向前移动
    int length_diff = list_length_1 - list_length_2;
    ListNode* longer_list_head = list_head_1;
    ListNode* shorter_list_head = list_head_2;
    if (list_length_1 < list_length_2){
        length_diff = list_length_2 - list_length_1;
        longer_list_head = list_head_2;
        shorter_list_head = list_head_1;
    }

    while (length_diff > 0){
        longer_list_head = longer_list_head->next;
        length_diff--;
    }

    // 同时移动两个链表指针，直到到达相同的节点
    while (longer_list_head != nullptr &&
            shorter_list_head != nullptr && longer_list_head != shorter_list_head){
        longer_list_head = longer_list_head->next;
        shorter_list_head = shorter_list_head->next;
    }
    return longer_list_head;
}