// 自顶向下
class Solution1 {
public:
    void backTrace(TreeNode* root){
        if(!root){
            return;
        }
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        if(root->left) invertTree(root->left);
        if(root->right) invertTree(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        backTrace(root);
        return root;
    }
};

// 自底向上
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root){
            return root;
        }
        TreeNode *left = invertTree(root->left);
        TreeNode *right = invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
};