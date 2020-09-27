// 充分利用有序性，确定路径

class Solution1 {
   public:
    vector<TreeNode*> path_p, path_q;
    void findPath(TreeNode* root, TreeNode* node, vector<TreeNode*>& path) {
        TreeNode* temp = root;
        while (temp->val != node->val) {
            path.push_back(temp);
            if (temp->val > node->val) {
                temp = temp->left;
            } else {
                temp = temp->right;
            }
        }
        path.push_back(temp);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        findPath(root, p, path_p);
        findPath(root, q, path_q);
        TreeNode* ret;
        for (int i = 0; i < min(path_p.size(), path_q.size()); i++) {
            if (path_p[i]->val == path_q[i]->val) {
                ret = path_p[i];
            } else {
                break;
            }
        }
        return ret;
    }
};

class Solution2 {
   public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* temp = root;
        TreeNode* ret = nullptr;
        while (true) {
            if (temp->val > p->val && temp->val > q->val) {
                temp = temp->left;
            } else if (temp->val < p->val && temp->val < q->val) {
                temp = temp->right;
            } else {
                ret = temp;
                break;
            }
        }
        return ret;
    }
};