// DIY
class Solution1 {
   public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *cur1 = l1, *cur2 = l2;
        int carry = 0;
        ListNode *head, *cur = new ListNode();
        head = cur;
        int val, val1, val2;
        while (cur1 && cur2) {
            val1 = cur1->val, val2 = cur2->val;
            val = (val1 + val2 + carry) % 10;
            carry = (val1 + val2 + carry) / 10;
            ListNode *newNode = new ListNode(val);
            cur->next = newNode;
            cur = newNode;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        while (cur1) {
            val1 = cur1->val;
            val = (val1 + carry) % 10;
            carry = (val1 + carry) / 10;
            ListNode *newNode = new ListNode(val);
            cur->next = newNode;
            cur = newNode;
            cur1 = cur1->next;
        }
        while (cur2) {
            val2 = cur2->val;
            val = (val2 + carry) % 10;
            carry = (val2 + carry) / 10;
            ListNode *newNode = new ListNode(val);
            cur->next = newNode;
            cur = newNode;
            cur2 = cur2->next;
        }
        if (carry != 0) {
            ListNode *newNode = new ListNode(1);
            cur->next = newNode;
            cur = newNode;
        }
        cur->next = nullptr;
        return head->next;
    }
};

// official answer
class Solution {
   public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head = nullptr, *tail = nullptr;
        int carry = 0;
        int sum = 0;
        while (l1 || l2) {
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            sum = (val1 + val2 + carry) % 10;
            carry = (val1 + val2 + carry) / 10;
            if (!head) {
                head = tail = new ListNode(sum);
            } else {
                tail->next = new ListNode(sum);
                tail = tail->next;
            }
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        if (carry) {
            tail->next = new ListNode(carry);
        }
        return head;
    }
};