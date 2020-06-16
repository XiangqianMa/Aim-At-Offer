#include <queue>

using namespace std;

class Solution {
public:
    void Insert(int num)
    {
        if ((current_size & 1) == 0) {
            if (current_size > 0) {
                int min_num = min_heap.top();
                if (num > min_num) {
                    min_heap.pop();
                    min_heap.push(num);
                    num = min_num;
                }
            }
            max_heap.push(num);
        } else {
            int max_num = max_heap.top();
            if (num < max_num) {
                max_heap.pop();
                max_heap.push(num);
                num = max_num;
            }
            min_heap.push(num);
        }
        current_size++;
    }

    double GetMedian()
    { 
        if (current_size == 0) {
            return -1;
        }
        
        if ((current_size & 1) == 0) {
            return (max_heap.top() + min_heap.top()) / 2.0;
        } else {
            return max_heap.top();
        }
    }

private:
    int current_size = 0;
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
};