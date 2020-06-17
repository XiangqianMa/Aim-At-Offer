#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        queue<TreeNode*> node_queue;
        if (root) {
            node_queue.push(root);
        }
        
        vector<int> result;
        while (!node_queue.empty()) {
            auto current_node = node_queue.front();
            node_queue.pop();
            
            result.push_back(current_node->val);
            if (current_node->left) node_queue.push(current_node->left);
            if (current_node->right) node_queue.push(current_node->right);
        }
        
        return result;
    }
};