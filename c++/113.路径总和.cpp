class Solution {
   public:
    vector<vector<int>> ret;
    vector<int> path;
    void dfs(TreeNode* root, int sum) {
        if (!root) {
            return;
        }
        path.push_back(root->val);
        sum -= root->val;
        if (root->left == nullptr && root->right == nullptr && sum == 0) {
            ret.push_back(path);
        }
        dfs(root->left, sum);
        dfs(root->right, sum);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        dfs(root, sum);
        return ret;
    }
};

// WA
class Solution2 {
   public:
    vector<vector<int>> ret;
    vector<int> path;
    void dfs(TreeNode* root, int sum){
        if(!root){
            if(sum==0){
                ret.push_back(path);
            }
            return;
        }
        path.push_back(root->val);
        sum -= root->val;
        dfs(root->left, sum);
        dfs(root->right, sum);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        dfs(root, sum);
        return ret;
    }
};

// 预先判断，可以保证叶子节点只在第一次访问时记录路径
// Solution2中没有预先判断，在当前位置判断，就会导致访问两次叶子节点