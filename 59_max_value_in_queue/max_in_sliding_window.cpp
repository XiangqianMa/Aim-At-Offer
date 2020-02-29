//
// Created by mxq on 2020/2/29.
//

#include "max_in_sliding_window.h"


/**
 * @brief 找出滑动窗口的最大值
 * @param data
 * @param window_size
 * @return
 */
vector<int> FindMaxInSlidingWindow(const vector<int>& data, int window_size){
    if (data.empty() || window_size <= 0)
        throw "Invalid input.";

    vector<int> result;
    // 当前位于window的下标，双端队列，队列头部存放当前窗口的最大值
    deque<int> window_index;
    for (int index = 0; index < data.size(); index++){
        // 删除window_index中已经不在窗口中的下标
        while (index >= window_size && window_index.front() <= index - window_size)
            window_index.pop_front();

        // 从队尾开始去除比当前要插入的值小的数的下标
        while (!window_index.empty() && data[window_index.back()] < data[index])
            window_index.pop_back();
        // 插入当前下标
        window_index.push_back(index);
        if (index >= window_size - 1)  // 将队首元素加入结果中
            result.push_back(data[window_index.front()]);
    }
    return result;
}