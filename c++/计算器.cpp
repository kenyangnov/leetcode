class Solution1 {
public:
    int calculate(string s) {
        char op = '+';
        int val;
        istringstream iss(s);
        stack<int> st;
        while(iss>>val){
            if(op=='+'){
                st.push(val);
            } else if(op=='-'){
                st.push(-val);
            } else{
                int val_pre = st.top();
                st.pop();
                if(op=='*'){
                    st.push(val_pre*val);
                } else{
                    st.push(val_pre/val);
                }
            }
            iss>>op;
        }
        int ret=0;
        while(!st.empty()){
            ret+=st.top();
            st.pop();
        }
        return ret;
    }
};