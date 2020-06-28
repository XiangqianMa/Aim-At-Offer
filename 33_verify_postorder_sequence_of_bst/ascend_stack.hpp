// 参考：leetcode 剑指 Offer 33. 二叉搜索树的后序遍历序列题解区

#include <vector>
#include <stack>
#include <climits>

using namespace std;

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if (postorder.empty()) {
            return true;
        }
        
        int pre_root = INT_MAX;
        stack<int> ascend_stack;
        for (int i = postorder.size() - 1; i >= 0; i--) {
            if (postorder[i] > pre_root) return false;
            while (!ascend_stack.empty() && ascend_stack.top() > postorder[i]) {
                pre_root = ascend_stack.top();
                ascend_stack.pop();
            }

            ascend_stack.push(postorder[i]);
        }

        return true;
    }
};