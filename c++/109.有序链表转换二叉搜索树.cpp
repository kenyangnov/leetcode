/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
   public:
    ListNode *getMedium(ListNode *left, ListNode *right) {  // 获取中位数
        ListNode *slow = left, *fast = left;
        while (fast != right && fast->next != right) {
            fast = fast->next;
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }

    TreeNode *buildTree(ListNode *left, ListNode *right) {
        if (left == right) {
            return nullptr;
        }
        ListNode *mid = getMedium(left, right);
        TreeNode *root = new TreeNode(mid->val);
        root->left = buildTree(left, mid);
        root->right = buildTree(mid->next, right);
        return root;
    }

    int getLength(ListNode *head) {
        int ret = 0;
        while (head != nullptr) {
            head = head->next;
            ret++;
        }
        return ret;
    }

    TreeNode *buildTree(ListNode *&head, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        int mid = (left + right) / 2;
        // int mid = (left+right+1)/2; ???
        TreeNode *root = new TreeNode();
        root->left = buildTree(head, left, mid - 1);
        root->val = head->val;
        head = head->next;
        root->right = buildTree(head, mid + 1, right);
        return root;
    }

    TreeNode *sortedListToBST(ListNode *head) {
        // return buildTree(head, nullptr);
        int length = getLength(head);
        return buildTree(head, 0, length - 1);
    }
};