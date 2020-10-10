// 集合
class Solution1 {
   public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *cur = head;
        unordered_set<ListNode *> visited;
        while (cur) {
            if (visited.count(cur)) {
                return cur;
            }
            visited.insert(cur);
            cur = cur->next;
        }
        return nullptr;
    }
};

// 快慢指针：判断存在环形并计算环长
// 双指针：一个指针移动提前量（圈长）后，另一个指针再移动，下次相遇即为交点
class Solution {
   public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        ListNode *slow = head, *fast = head->next;
        while (slow != fast) {
            if (fast == nullptr || fast->next == nullptr) {
                return nullptr;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = fast->next;
        int cnt = 1;
        while (fast != slow) {
            fast = fast->next;
            cnt++;
        }
        slow = fast = head;
        while (cnt--) {
            fast = fast->next;
        }
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};