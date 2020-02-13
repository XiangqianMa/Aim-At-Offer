//
// Created by mxq on 2020/2/13.
//

#include "reverse_list.h"


/**
 * @brief 反转单链表
 * @param list_head
 * @return 反转后的链表的表头
 */
ListNode* ReverseList(ListNode* list_head){
    if (list_head == nullptr || list_head->next == nullptr)
        return nullptr;
    ListNode* previous_node = nullptr;
    ListNode* current_node = list_head;

    ListNode* reverse_list_head = nullptr;
    while (current_node != nullptr){
        ListNode* next_node = current_node->next;
        if (next_node == nullptr)
            reverse_list_head = current_node;

        current_node->next = previous_node;
        previous_node = current_node;
        current_node = next_node;
    }
    return reverse_list_head;
}