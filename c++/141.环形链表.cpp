// 集合
class Solution1 {
   public:
    bool hasCycle(ListNode *head) {
        ListNode *cur = head;
        unordered_set<ListNode *> visited;
        while (cur) {
            if (visited.count(cur)) {
                return true;
            }
            visited.insert(cur);
            cur = cur->next;
        }
        return false;
    }
};

// 快慢指针
class Solution2 {
   public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        ListNode *slow = head, *fast = head->next;
        while (slow != fast) {
            if (fast == nullptr || fast->next == nullptr) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};