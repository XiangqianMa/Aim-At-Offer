#include <vector>

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
    vector<vector<int>> FindPath(TreeNode* root,int expectNumber) {
        if (root == nullptr) {
            return {};
        }
        
        vector<int> path;
        dfs(root, expectNumber, path, 0);
        return result;
    }
    
    void dfs(TreeNode* root, int expectNumber, vector<int> path, int sum) {
        if (root->left == nullptr && root->right == nullptr) {
            if (sum + root->val == expectNumber) {
                path.push_back(root->val);
                result.push_back(path);
            }
            return;
        }
        
        path.push_back(root->val);
        sum += root->val;
        if (root->left != nullptr) {
            dfs(root->left, expectNumber, path, sum);
        }
        
        if (root->right != nullptr) {
            dfs(root->right, expectNumber, path, sum);
        }
    }
    
private:
    vector<vector<int>> result;
};