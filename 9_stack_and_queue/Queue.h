//
// Created by mxq on 20-1-8.
//

#ifndef AIM_AT_OFFER_QUEUE_H
#define AIM_AT_OFFER_QUEUE_H

#include <stack>

using namespace std;


/*
 * 使用两个栈实现队列操作
 */
template <typename T>
class Queue {
public:
    Queue() = default;
    ~Queue() = default;

    void AppendTail(const T& node);
    T DeleteHead();
    bool is_empty();

private:
    stack<T> stack_1;
    stack<T> stack_2;
};


template <typename T>
void Queue<T>::AppendTail(const T &node) {
    stack_1.push(node);
}

template <typename T>
T Queue<T>::DeleteHead() {
    // 当栈2为空时，将栈1的元素依次出栈放入栈2
    if (stack_2.empty()){
        while (!stack_1.empty()){
            T &node = stack_1.top();
            stack_1.pop();
            stack_2.push(node);
        }
    }
    if (stack_2.empty())
        throw "queue is empty";
    T delete_node;
    delete_node = stack_2.top();
    stack_2.pop();

    return delete_node;
}


template <typename T>
bool Queue<T>::is_empty() {
    return stack_1.empty() && stack_2.empty();
}

#endif //AIM_AT_OFFER_QUEUE_H
