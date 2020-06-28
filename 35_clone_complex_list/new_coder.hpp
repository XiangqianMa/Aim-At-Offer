
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(nullptr), random(nullptr) {
    }
};

typedef RandomListNode Node;

class Solution {
public:
    Node* Clone(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        // 在原始节点之后创建新的节点
        auto temp_head = head;
        while (temp_head) {
            auto node = new Node(temp_head->label);
            node->next = temp_head->next;
            temp_head->next = node;
            temp_head = node->next;
        }

        // 连接random指针
        temp_head = head;
        while (temp_head) {
            auto random = temp_head->random;
            if (random != nullptr) {
                temp_head->next->random = random->next;
            }
            temp_head = temp_head->next->next;
        }

        temp_head = head;
        auto dummy_head = new Node(-1);
        dummy_head->next = temp_head->next;
        auto temp_node = dummy_head->next;
        while (temp_head) {
            temp_head->next = temp_node->next;
            if (temp_node->next)
                temp_node->next = temp_node->next->next;
            temp_head = temp_head->next;
            temp_node = temp_node->next;
        }

        return dummy_head->next;
    }
};