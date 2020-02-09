//
// Created by mxq on 2020/2/9.
//

#include "delete_duplication.h"


/**
 * @brief 删除链表中的重复节点
 * @param list_head 指向表头的指针
 */
void DeleteDuplication(ListNode** list_head){
    if (list_head == nullptr || *list_head == nullptr)
        return;
    ListNode* previous_node_ptr = nullptr;
    ListNode* current_node_ptr = *list_head;

    while (current_node_ptr != nullptr){
        ListNode* next_node_ptr = current_node_ptr->next;
        bool need_delete = false;
        if (next_node_ptr != nullptr && current_node_ptr->val == next_node_ptr->val)
            need_delete = true;

        if (!need_delete){
            previous_node_ptr = current_node_ptr;
            current_node_ptr = next_node_ptr;
        } else {
            int value = current_node_ptr->val;
            ListNode* node_to_be_deleted = current_node_ptr;
            // 删除重复的节点
            while (node_to_be_deleted != nullptr && node_to_be_deleted->val == value){
                next_node_ptr = node_to_be_deleted->next;
                delete node_to_be_deleted;
                node_to_be_deleted = nullptr;
                node_to_be_deleted = next_node_ptr;
            }
            if (previous_node_ptr == nullptr){
                *list_head = next_node_ptr;
            } else {
                previous_node_ptr->next = next_node_ptr;
            }
            current_node_ptr = next_node_ptr;
        }
    }
}