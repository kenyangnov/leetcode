/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> qe;
        vector<double> ret;
        qe.push(root);
        TreeNode* cur;
        while(!qe.empty()){
            int q_size = qe.size();
            double sum = 0;
            for(int i=0; i<q_size; i++){
                cur = qe.front();
                qe.pop();
                sum += cur->val;
                if(cur->left) qe.push(cur->left);
                if(cur->right) qe.push(cur->right);
            }
            ret.push_back(sum/q_size);
        }
        return ret;
    }
};