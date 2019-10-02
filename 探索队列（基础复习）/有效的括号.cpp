class Solution {
private:
    stack<char> brackets;
public:
    bool isValid(string s) {
        int len = s.length();
        if(len%2!=0){
            return false;
        }
        for(int i=0;i<len;i++){
            if(!brackets.empty()){
                if(s[i]=='('||s[i]=='['||s[i]=='{'){
                    brackets.push(s[i]);
                }
                else{
                    if(s[i]==')'){
                        if(brackets.top()=='('){
                            brackets.pop();
                        }
                        else{
                            return false;
                        }
                    }
                    else if(s[i]==']'){
                        if(brackets.top()=='['){
                            brackets.pop();
                        }
                        else{
                            return false;
                        }
                    }
                    else{
                        if(brackets.top()=='{'){
                            brackets.pop();
                        }
                        else{
                            return false;
                        }
                    }
                }
            }
            else{
                brackets.push(s[i]);
            }
        }
        if(brackets.empty()){
            return true;
        }
        return false;
    }
};