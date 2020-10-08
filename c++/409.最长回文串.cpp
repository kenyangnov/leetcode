class Solution {
   public:
    int longestPalindrome(string s) {
        unordered_map<char, int> cnt;
        for (char &ch : s) {
            cnt[ch]++;
        }
        int ret = 0;
        for (auto &p : cnt) {
            ret += p.second / 2 * 2;
            if (ret % 2 == 0 && p.second % 2 == 1) {
                ret++;
            }
        }
        return ret;
    }
};