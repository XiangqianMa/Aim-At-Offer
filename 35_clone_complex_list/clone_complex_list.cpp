//
// Created by mxq on 2020/2/18.
//

#include "clone_complex_list.h"


/**
 * @brief 复制复杂链表
 * @param list_head
 * @return
 */
ComplexListNode* CloneComplexList(ComplexListNode* list_head){
    if (list_head == nullptr)
        return nullptr;
    CloneNodes(list_head);
    ConnectSiblingNodes(list_head);
    return SplitNodes(list_head);
}


/**
 * @brief 在原始链表的基础上进行节点复制
 * @param list_head
 */
void CloneNodes(ComplexListNode* list_head){
    ComplexListNode* temp_node = list_head;
    while (temp_node != nullptr){
        auto new_node = new ComplexListNode;
        new_node->val = temp_node->val;
        new_node->next = temp_node->next;
        new_node->sibling = nullptr;
        temp_node->next = new_node;
        temp_node = new_node->next;
    }
}


/**
 * @brief 连接复制节点与其silbing节点
 * @param list_head
 */
void ConnectSiblingNodes(ComplexListNode* list_head){
    ComplexListNode* temp_node = list_head;
    while (temp_node != nullptr){
        if (temp_node->sibling != nullptr){
            temp_node->next->sibling = temp_node->sibling->next;
        }
        else {
            temp_node->next->sibling = nullptr;
        }
        temp_node = temp_node->next->next;
    }
}


/**
 * @brief 将原链表和复制的链表拆分开
 * @param list_head
 * @return 复制的链表的表头指针
 */
ComplexListNode* SplitNodes(ComplexListNode* list_head){
    ComplexListNode* temp_node = list_head;
    ComplexListNode* cloned_head= list_head->next;
    ComplexListNode* temp_cloned_node = cloned_head;

    while (temp_node != nullptr){
        temp_node->next = temp_node->next->next;
        if (temp_cloned_node->next != nullptr)
            temp_cloned_node->next = temp_cloned_node->next->next;

        temp_node = temp_node->next;
        temp_cloned_node = temp_cloned_node->next;
    }
    return cloned_head;
}
