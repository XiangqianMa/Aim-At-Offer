//
// Created by mxq on 2020/2/16.
//

#include "stack_push_pop_order.h"


/**
 * @brief 判断pop_order是否是压栈序列push_order的出栈序列
 * @param push_order
 * @param pop_order
 * @return
 */
bool IsStackPushPopOrder(vector<int> push_order, vector<int> pop_order){
    if (push_order.empty() || pop_order.empty())
        return false;
    stack<int> assistant_stack;

    auto push_iter = push_order.begin();
    auto pop_iter = pop_order.begin();
    while (pop_iter != pop_order.end()){
        // 依次将压栈序列中的元素压栈，直到栈顶出现出栈序列的当前元素
        while (assistant_stack.empty() || assistant_stack.top() != *pop_iter){
            if (push_iter == push_order.end())
                break;
            assistant_stack.push(*push_iter);
            push_iter++;
        }
        if (assistant_stack.top() != *pop_iter)
            break;
        assistant_stack.pop();
        pop_iter++;
    }
    return  assistant_stack.empty() && pop_iter == pop_order.end();
}