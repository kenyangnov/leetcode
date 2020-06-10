// 单调栈解决 next greater number 问题
// 在维护单调栈的过程中解决问题

class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> s;
        vector<int> ans(T.size());
        for (int i = T.size() - 1; i >= 0; i--) {
            while (!s.empty() && T[s.top()] <= T[i]) {
                s.pop();
            }
            ans[i] = s.empty() ? 0 : (s.top() - i);
            s.push(i);
        }
        return ans;
    }
};