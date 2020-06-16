#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        deque<int> ascend_queue;
        vector<int> result;
           
        for (int i = 0; i < num.size(); i++) {
            while (!ascend_queue.empty() && num[i] > num[ascend_queue.back()]) {
                ascend_queue.pop_back();
            }
            
            ascend_queue.push_back(i);
            if (i >= size && ascend_queue.front() <= (i - size)) {
                ascend_queue.pop_front();
            }
            if (i >= size - 1) {
                result.push_back(num[ascend_queue.front()]);
            }
        }
        return result;
    }
};