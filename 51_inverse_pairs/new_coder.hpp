#include <vector>

using namespace std;

class Solution {
public:
    int InversePairs(vector<int> data) {
        int count = 0;
        auto merged_data = merge(data, count);
        return count;
    }
    
    vector<int> merge(const vector<int>& data, int& count) {
        if (data.size() <= 1) {
            return data;
        }
        
        int mid = data.size() / 2;
        vector<int> left_part(data.begin(), data.begin() + mid);
        vector<int> right_part(data.begin() + mid, data.end());
        
        auto left = merge(left_part, count);
        count = count % 1000000007;
        auto right = merge(right_part, count);
        count = count % 1000000007;
        
        int ptr1 = 0;
        int ptr2 = 0;
        vector<int> merged;
        while (ptr1 < left.size() && ptr2 < right.size()) {
            if (left[ptr1] <= right[ptr2]) {
                merged.push_back(left[ptr1]);
                ptr1++;
            } else {
                count += (left.size() - ptr1);
                count = count % 1000000007;
                merged.push_back(right[ptr2]);
                ptr2++;
            }
        }
        
        while (ptr1 < left.size()) {
            merged.push_back(left[ptr1]);
            ptr1++;
        }
        while (ptr2 < right.size()) {
            merged.push_back(right[ptr2]);
            ptr2++;
        }
        
        return merged;
    }
};