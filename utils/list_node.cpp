//
// Created by mxq on 2020/2/26.
//

#include "list_node.h"

/**
 * @brief 统计单向链表的节点数目
 * @param list_head
 * @return
 */
int CountListsNodes(ListNode* list_head){
    int count = 0;
    while (list_head != nullptr){
        count++;
        list_head = list_head->next;
    }
    return count;
}



