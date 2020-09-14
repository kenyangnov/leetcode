class Solution {
public:
    int removePalindromeSub(string s) {
        if(s.length()==0){
            return 0;
        }
        int i=0, j=s.length()-1;
        for(;i<j; i++,j--){
            if(s[i]!=s[j]){
                return 2;
            }
        }
        return 1;
    }
};