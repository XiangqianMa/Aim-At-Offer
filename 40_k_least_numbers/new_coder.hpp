#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if (k == 0 || k > input.size()) {
            return {};
        }
        priority_queue<int> min_heap;
        
        for (int i = 0; i < input.size(); i++) {
            if (i < k) {
                min_heap.push(input[i]);
                continue;
            }
            
            if (input[i] < min_heap.top()) {
                min_heap.pop();
                min_heap.push(input[i]);
            }
        }
        
        vector<int> result;
        while (!min_heap.empty()) {
            int temp = min_heap.top();
            min_heap.pop();
            result.push_back(temp);
        }
        return result;
    }
};