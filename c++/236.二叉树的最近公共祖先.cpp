// DIY
class Solution1 {
   public:
    unordered_map<int, TreeNode*> parent;
    unordered_map<int, bool> visited;
    void dfs(TreeNode* root) {
        if (root->left) {
            parent[root->left->val] = root;
            dfs(root->left);
        }
        if (root->right) {
            parent[root->right->val] = root;
            dfs(root->right);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root);
        TreeNode* temp = p;
        TreeNode* ret = nullptr;
        visited[temp->val] = true;
        while (temp->val != root->val) {
            temp = parent[temp->val];
            visited[temp->val] = true;
        }
        if (visited[q->val]) {
            return q;
        }
        temp = q;
        while (temp->val != root->val) {
            if (visited[temp->val]) {
                ret = temp;
                break;
            }
            temp = parent[temp->val];
        }
        if (temp->val == root->val) {
            ret = root;
        }
        return ret;
    }
};

// 官方的判断逻辑更优雅，另外通过增加边界元素（即：parent[root]=nullptr）来简化边界判断逻辑
class Solution2 {
   public:
    unordered_map<int, TreeNode*> parent;
    unordered_map<int, bool> visited;
    void dfs(TreeNode* root) {
        if (root->left) {
            parent[root->left->val] = root;
            dfs(root->left);
        }
        if (root->right) {
            parent[root->right->val] = root;
            dfs(root->right);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        parent[root->val] = nullptr;
        dfs(root);
        TreeNode* temp = p;
        TreeNode* ret = nullptr;
        while (temp) {
            visited[temp->val] = true;
            temp = parent[temp->val];
        }
        temp = q;
        while (temp) {
            if (visited[temp->val]) {
                ret = temp;
                break;
            }
            temp = parent[temp->val];
        }
        return ret;
    }
};

// TODO: 递归实现