struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(nullptr), right(nullptr) {
    }
};

class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        dfs(pRoot, k);
        return result;
    }

    void dfs(TreeNode* root, int k) {
        if (root == nullptr) {
            return;
        }
        
        dfs(root->left, k);
        index++;
        if (index == k) {
            result = root;
            return;
        }
        dfs(root->right, k);
    }

private:
    int index = 0;
    TreeNode* result = nullptr;
};