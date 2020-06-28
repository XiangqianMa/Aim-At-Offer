
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
    bool HasSubtree(TreeNode* A, TreeNode* B) {
        if (A == nullptr || B == nullptr) {
            return false;
        }

        bool is_equal = false;
        if (A->val == B->val) {
            is_equal = isEqual(A, B);
        }
        if (is_equal) {
            return true;
        }
        
        return HasSubtree(A->left, B) || HasSubtree(A->right, B);
    }

    bool isEqual(TreeNode* tree1, TreeNode* tree2) {
        if (tree1 == nullptr) {
            return false;
        }

        if (tree1->val != tree2->val) {
            return false;
        }

        bool left = true;
        if (tree2->left != nullptr) {
            left = isEqual(tree1->left, tree2->left);
        }

        bool right = true;
        if (tree2->right != nullptr) {
            right = isEqual(tree1->right, tree2->right);
        }

        return left && right;
    }
};
