//
// Created by mxq on 2020/2/16.
//

#ifndef AIM_AT_OFFER_STACK_WITH_MIN_H
#define AIM_AT_OFFER_STACK_WITH_MIN_H

#include <stack>
using namespace std;


/**
 * @brief 带有min函数的栈
 * @tparam T
 */
template <typename T>
class StackWithMin{
public:
    void push(T val) {
        data.push(val);
        T min = val;
        if (!min_data.empty() && val > min_data.top())
            min = min_data.top();
        min_data.push(min);
    }

    void pop(){
        if (!data.empty())
            data.pop();
        if (!min_data.empty())
            min_data.pop();
    }

    T min() {
        assert(!data.empty() && !min_data.empty());
        return min_data.top();
    }

private:
    stack<T> data;  // 栈中的数据
    stack<T> min_data;  // 存储每一个阶段对应的最小值
};

#endif //AIM_AT_OFFER_STACK_WITH_MIN_H
