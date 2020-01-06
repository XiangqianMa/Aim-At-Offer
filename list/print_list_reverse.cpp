//
// Created by mxq on 20-1-4.
//

#include "print_list_reverse.h"


/*
 * 向链表结尾插入新节点
 */
void add_to_tail(ListNode **list_head, int value)
{
    auto *new_node = new ListNode();
    new_node->m_nValue = value;
    new_node->m_pNext = nullptr;

    if(*list_head == nullptr)
        *list_head = new_node;
    else{
        ListNode *node = *list_head;
        while(node->m_pNext != nullptr)
            node=node->m_pNext;
        node->m_pNext = new_node;
    }
}


/*
 * 使用栈的方式从尾到头打印链表
 */
void print_list_reverse_iterative(ListNode *list_head)
{
    stack<ListNode*> node_stack;

    ListNode *node = list_head;
    while (node != nullptr){
        node_stack.push(node);
        node = node->m_pNext;
    }
    while(!node_stack.empty()){
        node = node_stack.top();
        cout << node->m_nValue << endl;
        node_stack.pop();
    }
}


void print_list_reverse_recursive(ListNode *list_head)
{
    if (list_head != nullptr){
        if (list_head->m_pNext != nullptr){
            print_list_reverse_recursive(list_head->m_pNext);
        }
        cout << list_head->m_nValue << endl;
    }
}