//
// Created by mxq on 2020/2/13.
//

#include "find_kth_to_tail.h"


/**
 * @brief 找出链表中倒数第K个节点
 * @param list_head
 * @param k
 * @return
 */
ListNode* FindKthToTail(ListNode* list_head, unsigned int k){
    if (list_head == nullptr || k == 0)
        return nullptr;

    ListNode* fast_ptr = list_head;
    ListNode* slow_ptr = list_head;
    for (int i = 0; i < k-1; i++){
        // 检查节点数目是否少于k个
        if (fast_ptr->next == nullptr)
            return nullptr;
        fast_ptr = fast_ptr->next;
    }

    // fast_ptr指向尾节点时，slow_ptr指向倒数k个节点
    while (fast_ptr->next != nullptr){
        fast_ptr = fast_ptr->next;
        slow_ptr = slow_ptr->next;
    }
    return slow_ptr;
}