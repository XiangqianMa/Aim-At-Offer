//
// Created by mxq on 2020/2/22.
//

#ifndef AIM_AT_OFFER_STREAM_MEDIAN_H
#define AIM_AT_OFFER_STREAM_MEDIAN_H

#include <vector>

using namespace std;


/**
 * @brief 计算输入流的中位数
 * @tparam T
 */
template <typename T>
class DynamicArray{
public:
    void Insert(T num){
        if ((min_heap.size() + max_heap.size()) & 1){  // 元素数目为奇数，将其插入大顶堆中
            // 检查当前元素是否比小顶堆的最小元素大
            if (min_heap.size() > 0 && num > min_heap[0]) {
                min_heap.push_back(num);
                push_heap(min_heap.begin(), min_heap.end(), greater<T>());

                num = min_heap[0];
                pop_heap(min_heap.begin(), min_heap.end(), greater<T>());
                min_heap.pop_back();
            }

            max_heap.push_back(num);
            push_heap(max_heap.begin(), max_heap.end(), less<T>());
        }
        else {  // 元素数目为偶数，将其插入小顶堆中
            // 检查当前元素是否比大顶堆的最大元素小
            if (max_heap.size() > 0 && num < max_heap[0]){
                max_heap.push_back(num);
                push_heap(max_heap.begin(), max_heap.end(), less<T>());

                num = max_heap[0];
                pop_heap(max_heap.begin(), max_heap.end(), less<T>());
                max_heap.pop_back();
            }

            min_heap.push_back(num);
            push_heap(min_heap.begin(), min_heap.end(), greater<T>());
        }
    }

    T GetMedian(){
        if (min_heap.size() + max_heap.size() == 0)
            throw "No numbers";

        T result;
        if ((min_heap.size() + max_heap.size()) & 1){
            result = min_heap[0];
        }
        else {
            result = (max_heap[0] + min_heap[0]) >> 1;
        }
        return result;
    }

private:
    vector<T> min_heap;
    vector<T> max_heap;
};


#endif //AIM_AT_OFFER_STREAM_MEDIAN_H
