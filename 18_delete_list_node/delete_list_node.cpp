//
// Created by mxq on 2020/2/5.
//

#include "delete_list_node.h"


/**
 * @brief: 在O(1)的时间复杂度内删除列表中的节点
 */
void DeleteNode(ListNode** list_head, ListNode* node_to_be_deleted){
    if (list_head == nullptr || *list_head == nullptr || node_to_be_deleted == nullptr)
        return;
    // 被删除的节点为头节点
    if (node_to_be_deleted == *list_head) {
        *list_head = node_to_be_deleted->next;
        delete node_to_be_deleted;
        node_to_be_deleted = nullptr;
    }
    // 被删除的节点为尾节点
    else if (node_to_be_deleted->next == nullptr){
        ListNode* node_ptr = *list_head;
        while (node_ptr->next != node_to_be_deleted){
            node_ptr = node_ptr->next;
        }
        node_ptr->next = node_to_be_deleted->next;
        delete node_to_be_deleted;
        node_to_be_deleted = nullptr;
    }
    // 被删除的节点为其他节点
    else {
        node_to_be_deleted->val = node_to_be_deleted->next->val;
        ListNode *node_ptr = node_to_be_deleted->next;
        node_to_be_deleted->next = node_to_be_deleted->next->next;
        delete node_to_be_deleted->next;
        node_to_be_deleted->next = nullptr;
    }
}