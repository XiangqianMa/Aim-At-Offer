
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
    void Mirror(TreeNode *pRoot) {
        if (pRoot == nullptr) {
            return;
        }
        
        Mirror(pRoot->left);
        Mirror(pRoot->right);
        
        auto temp = pRoot->right;
        pRoot->right = pRoot->left;
        pRoot->left = temp;
    }
};