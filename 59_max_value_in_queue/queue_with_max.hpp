//
// Created by mxq on 2020/3/1.
//

#ifndef AIM_AT_OFFER_QUEUE_WITH_MAX_H
#define AIM_AT_OFFER_QUEUE_WITH_MAX_H

#include <deque>

template <typename T>
class QueueWithMax{
public:
    QueueWithMax(): current_index(0){};

    void PushBack(T val){
        DataWithIndex element;
        element.val = val;
        element.index = current_index;

        // 将当前数据插入max_data中
        while (!max_data.empty() && element.val > max_data.back().val){
            max_data.pop_back();
        }
        max_data.push_back(element);
        data.push_back(element);
        current_index++;
    }

    void PopFront(){
        if (data.empty())
            throw "Empty queue";
        DataWithIndex data_front = data.front();
        DataWithIndex max_data_front = max_data.front();
        // 判断当前数据是否在max_data中
        if (data_front.index == max_data_front.index)
            max_data.pop_front();
        data.pop_front();
    }

    T Max(){
        if (max_data.empty())
            throw "Empty Queue";
        DataWithIndex max = max_data.front();
        return max.val;
    }

private:
    struct DataWithIndex{
        T val;
        int index;
    };
    std::deque<DataWithIndex> data;
    std::deque<DataWithIndex> max_data;
    int current_index;
};

#endif //AIM_AT_OFFER_QUEUE_WITH_MAX_H
