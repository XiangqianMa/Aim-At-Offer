//
// Created by mxq on 2020/2/13.
//

#include "find_entry_node_of_loop.h"



/**
 * @brief 查找链表中的环的入口节点
 * @param list_head
 * @return
 */
ListNode* FindEntryNodeOfLoop(ListNode* list_head){
    ListNode* meet_node = FindMeetNode(list_head);
    if (list_head == nullptr)
        return nullptr;

    // 计算环中节点的个数
    ListNode* temp_node = meet_node;
    unsigned int loop_node_number = 1;
    while (meet_node->next != temp_node){
        loop_node_number++;
        meet_node = meet_node->next;
    }

    // 将temp_node从头节点开始向后移动loop_node_number次
    temp_node = list_head;
    for (int i = 0; i < loop_node_number; i++){
        temp_node = temp_node->next;
    }

    // 当两个节点相遇的时候，相遇节点即为环的入口节点
    ListNode* entry_node = list_head;
    while (entry_node != temp_node){
        entry_node = entry_node->next;
        temp_node = temp_node->next;
    }
    return entry_node;
}


/**
 * @brief 查找相遇节点
 * @param list_head
 * @return
 */
ListNode* FindMeetNode(ListNode* list_head){
    if (list_head == nullptr)
        return nullptr;

    ListNode* fast_ptr = list_head->next;
    ListNode* slow_ptr = list_head;

    while (fast_ptr != nullptr && slow_ptr != nullptr){
        // 两个指针相遇则返回
        if (fast_ptr == slow_ptr)
            return fast_ptr;

        fast_ptr = fast_ptr->next;
        if (fast_ptr != nullptr)
            fast_ptr = fast_ptr->next;

        slow_ptr = slow_ptr->next;
    }
    return nullptr;
}
