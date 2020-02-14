//
// Created by mxq on 2020/2/14.
//

#include "merge_two_sorted_array.h"


/**
 * @brief 采用双指针的方式合并两个有序数组
 * @param list_head_a
 * @param list_node_b
 * @return
 */
ListNode* MergeTwoSortedList(ListNode* list_head_a, ListNode* list_node_b){
    if (list_head_a == nullptr)
        return list_node_b;
    else if (list_node_b == nullptr)
        return list_head_a;

    ListNode* merged_list_head;
    auto temp_node = new ListNode;
    merged_list_head = temp_node;

    ListNode* node_ptr_a = list_head_a;
    ListNode* node_ptr_b = list_node_b;

    while (node_ptr_a != nullptr && node_ptr_b != nullptr){
        if (node_ptr_a->val <= node_ptr_b->val){
            temp_node->next = node_ptr_a;
            node_ptr_a = node_ptr_a->next;
        } else {
            temp_node->next = node_ptr_b;
            node_ptr_b = node_ptr_b->next;
        }
        temp_node = temp_node->next;
    }

    if (node_ptr_a != nullptr)
        temp_node->next = node_ptr_a;
    else
        temp_node->next = node_ptr_b;
    temp_node = merged_list_head;
    merged_list_head = merged_list_head->next;
    delete temp_node;
    return merged_list_head;
}


/**
 * @brief 采用递归的方式合并两个已排序的指针
 * @param list_head_a
 * @param list_head_b
 * @return
 */
ListNode* MergeTwoSortedListRecursive(ListNode* list_head_a, ListNode* list_head_b){
    if (list_head_a == nullptr)
        return list_head_b;
    else if (list_head_b == nullptr)
        return list_head_a;

    ListNode* merged_list_head = nullptr;
    if (list_head_a->val <= list_head_b->val){
        merged_list_head = list_head_a;
        merged_list_head->next = MergeTwoSortedListRecursive(list_head_a->next, list_head_b);
    } else {
        merged_list_head = list_head_b;
        merged_list_head->next = MergeTwoSortedListRecursive(list_head_a, list_head_b->next);
    }
    return merged_list_head;
}