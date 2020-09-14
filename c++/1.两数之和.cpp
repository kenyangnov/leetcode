class Solution {
public:
    static bool compare(pair<int, int> a, pair<int, int> b) {
        return a.second<b.second;
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> temp;
        for(int i=0; i<nums.size(); i++){
            temp.push_back({i, nums[i]});
        }
        sort(temp.begin(), temp.end(), compare);
        int i=0, j=temp.size()-1;
        while(i<j){
            if(temp[i].second+temp[j].second<target){
                i++;
            } else if(temp[i].second+temp[j].second>target){
                j--;
            } else{
                return {temp[i].first, temp[j].first};
            }
        }
        return {};
    }
};