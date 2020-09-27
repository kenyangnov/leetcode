// TODO: 前序遍历


// 中序遍历
class Solution {
   public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (!st.empty() || cur) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }
            ret.push_back(st.top()->val);
            cur = st.top()->right;
            st.pop();
        }
        return ret;
    }
};

// 后序遍历
class Solution {
   public:
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode* cur = root;
        TreeNode* pre = NULL;
        vector<int> res;
        stack<TreeNode*> st;
        while (cur || !st.empty()) {
            if (cur) {
                st.push(cur);
                cur = cur->left;
            } else {
                cur = st.top();
                if (cur->right && cur->right != pre) {
                    cur = cur->right;
                } else {
                    res.push_back(cur->val);
                    st.pop();
                    pre = cur;
                    cur = NULL;
                }
            }
        }
        return res;
    }
};