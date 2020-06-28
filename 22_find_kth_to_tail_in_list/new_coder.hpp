
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(nullptr) {
	}
};

class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if (pListHead == nullptr) {
            return nullptr;
        }
        
        auto fast_ptr = pListHead;
        auto slow_ptr = pListHead;
        while (k - 1 > 0) {
            fast_ptr = fast_ptr->next;
            if (fast_ptr == nullptr) {
                return nullptr;
            }
            k--;
        }
        
        while (fast_ptr->next != nullptr) {
            fast_ptr = fast_ptr->next;
            slow_ptr = slow_ptr->next;
        }
        return slow_ptr;
    }
};