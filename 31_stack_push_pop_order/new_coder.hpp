#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        if (pushV.empty() && popV.empty()) {
            return true;
        }
        
        stack<int> my_stack;
        int pop_index = 0;
        int push_index = 0;
        while (pop_index != popV.size()) {
            while (my_stack.empty() || my_stack.top() != popV[pop_index]) {
                if (push_index == pushV.size()) {
                    return false;
                }
                my_stack.push(pushV[push_index]);
                push_index++;
            }
            
            while (!my_stack.empty() && my_stack.top() == popV[pop_index]) {
                my_stack.pop();
                pop_index++;
            }
        }
        
        return true;
    }
};