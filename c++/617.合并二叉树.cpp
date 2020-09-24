class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr) {
            return t2;
        }
        if (t2 == nullptr) {
            return t1;
        }
        auto t = new TreeNode(t1->val + t2->val);
        t->left = mergeTrees(t1->left, t2->left);
        t->right = mergeTrees(t1->right, t2->right);
        return t;
    }
};

class Solution2 {
   public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if ((t1 == nullptr) && (t2 == nullptr)) {
            return nullptr;
        }
        int a, b;
        TreeNode *a_left, *a_right, *b_left, *b_right;
        if (t1 == nullptr) {
            a = 0;
            a_left = nullptr;
            a_right = nullptr;
        } else {
            a = t1->val;
            a_left = t1->left;
            a_right = t1->right;
        }
        if (t2 == nullptr) {
            b = 0;
            b_left = nullptr;
            b_right = nullptr;
        } else {
            b = t2->val;
            b_left = t2->left;
            b_right = t2->right;
        }
        auto t = new TreeNode(a + b);
        t->left = mergeTrees(a_left, b_left);
        t->right = mergeTrees(a_right, b_right);
        return t;
    }
};