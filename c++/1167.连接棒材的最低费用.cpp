class Solution {
   public:
    /**
     * @param sticks: the length of sticks
     * @return: Minimum Cost to Connect Sticks
     */
    int MinimumCost(vector<int> &sticks) {
        priority_queue<int, vector<int>, greater<int>> heap_min;
        for (int stick : sticks) {
            heap_min.push(stick);
        }
        int ret = 0;
        while (heap_min.size() > 1) {
            int m1 = heap_min.top();
            heap_min.pop();
            int m2 = heap_min.top();
            heap_min.pop();
            ret += (m1 + m2);
            heap_min.push(m1 + m2);
        }
        return ret;
    }
};