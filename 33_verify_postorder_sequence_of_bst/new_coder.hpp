#include <vector>

using namespace std;

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.empty()) {
            return false;
        }
        
        return dfs(sequence);
    }
    
    bool dfs(vector<int> sequence) {
        if (sequence.empty() || sequence.size() == 1) {
            return true;
        }
        
        int root = sequence.back();
        int i = 0;
        while (sequence[i] < root) {
            i++;
        }
        
        int j = i;
        while (j < sequence.size() - 1) {
            if (sequence[j] < root) {
                return false;
            }
            j++;
        }
        
        auto left = vector<int>(sequence.begin(), sequence.begin() + i);
        auto right = vector<int>(sequence.begin() + i, sequence.end() - 1);
        
        bool is_left = dfs(left);
        bool is_right = dfs(right);
        
        return is_left && is_right;
    }
};