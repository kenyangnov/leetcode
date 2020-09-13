class Solution1 {
public:
    bool isPalindrome(int x) {
        if(x<0 || (x%10==0&&x!=0)){
            return false;
        }
        stack<int> st;
        int temp = x;
        while(temp!=0){
            st.push(temp%10);
            temp = temp/10;
        }
        while(!st.empty()){
            if(st.top()!=x%10){
                return false;
            }
            x=x/10;
            st.pop();
        }
        return true;
    }
};

class Solution2 {
public:
    bool isPalindrome(int x) {
        if(x<0 || (x%10==0&&x!=0)){
            return false;
        }
        int revert = 0;
        while(x>revert){
            revert = revert*10+(x%10); 
            x = x/10;
        }
        return (x==revert)||(x==revert/10);
    }
};
