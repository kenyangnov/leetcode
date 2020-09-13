class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> hashchar(256, 0);
        for(char &ch:s){
            hashchar[ch]++;
        }
        int cnt=0;
        for(int &frequency:hashchar){
            if(frequency%2==1){
                cnt++;
            }
        }
        return cnt<=1;
    }
};