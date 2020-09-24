class Solution {
public:
    vector<int> nums, ret;
    int base=0, count=0, maxCount=0;
    void update(int x) {
        if (x == base) {
            ++count;
        } else {
            count = 1;
            base = x;
        }
        if (count == maxCount) {
            ret.push_back(base);
        }
        if (count > maxCount) {
            maxCount = count;
            ret = vector<int> {base};
            // ret.clear();
            // ret.push_back(base);
        }
    }

    void inorder(TreeNode* root){
        if(root){
            inorder(root->left);
            nums.push_back(root->val);
            inorder(root->right);
        }
    }

    vector<int> findMode(TreeNode* root) {
        inorder(root);
        for(int &val: nums){
            update(val);
        }
        return ret;
    }
};
// update策略：
// 首先更新 basebase 和 countcount:
//      如果该元素和 basebase 相等，那么 countcount 自增 1
//      否则将 basebase 更新为当前数字，countcount 复位为 1
// 然后更新  maxCountmaxCount：
//      如果  count = maxCount，那么说明当前的这个数字（basebase）出现的
//          次数等于当前众数出现的次数，将 basebase 加入 answeranswer 数组
//      如果  count > maxCount，那么说明当前的这个数字（basebase）出现的
//          次数大于当前众数出现的次数，因此，我们需要将 maxCountmaxCount 
//          更新为 countcount，清空 answer 数组后将 basebase 加入 answer 数组

// TLE
class Solution1 {
public:
    vector<int> nums, ret;
    unordered_map<int, int> m;
    
    void inorder(TreeNode* root){
        if(root){
            findMode(root->left);
            nums.push_back(root->val);
            findMode(root->right);
        }
    }

    vector<int> findMode(TreeNode* root) {
        inorder(root);
        
        for(int &val:nums){
            m[val]++;
        }
        int max_val = 0;
        for (auto iter = m.begin(); iter != m.end(); ++iter){
            max_val = max_val>iter->second?max_val:iter->second;
        }
        for (auto iter = m.begin(); iter != m.end(); ++iter){
            if(iter->second == max_val){
                ret.push_back(iter->first);
            }
        }
        return ret;
    }
};