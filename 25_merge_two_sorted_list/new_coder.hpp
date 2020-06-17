
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(nullptr) {
	}
};
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode* dummy_head = new ListNode(-1);
        auto temp_node = dummy_head;
        
        auto ptr1 = pHead1;
        auto ptr2 = pHead2;
        while (ptr1 != nullptr && ptr2 != nullptr) {
            if (ptr1->val < ptr2->val) {
                temp_node->next = ptr1;
                ptr1 = ptr1->next;
            } else {
                temp_node->next = ptr2;
                ptr2 = ptr2->next;
            }
            temp_node = temp_node->next;
        }
        
        auto ptr = ptr1 == nullptr? ptr2 : ptr1;
        while (ptr != nullptr) {
            temp_node->next = ptr;
            ptr = ptr->next;
            temp_node = temp_node->next;
        }
        
        return dummy_head->next;
    }
};