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

class Solution2 {
   public:
    int getPriority(char ch) {
        switch (ch) {
            case '+':
                return 1;
            case '-':
                return 1;
            case '*':
                return 2;
            case '/':
                return 2;
            default:
                return 0;
        }
    }

    // convert infix expression to postfix expression (reverse polish notation)
    string toRPN(string s) {
        //remove space from string
        auto itor = remove_if(s.begin(), s.end(), ::isspace);
        s.erase(itor, s.end());
        stack<char> op_st;
        istringstream iss(s);
        ostringstream oss;
        char ch, op;
        int val;
        while (iss.peek() != EOF) {
            ch = iss.peek();
            if (ch == '(') {
                iss >> op;
                op_st.push(op);
            } else if (ch == ')') {
                iss >> op;
                while (op_st.top() != '(') {
                    oss << op_st.top();
                    op_st.pop();
                }
                op_st.pop();
            } else if (ch >= '0' && ch <= '9') {
                iss >> val;
                oss << ' ' << val;
            } else {
                iss >> op;
                while (!op_st.empty() && getPriority(op_st.top()) >= getPriority(op)) {
                    oss << op_st.top();
                    op_st.pop();
                }
                op_st.push(op);
            }
        }
        while (!op_st.empty()) {
            oss << op_st.top();
            op_st.pop();
        }
        iss.clear();
        return oss.str();
    }

    int calculate(string s) {
        s = toRPN(s);
        istringstream iss(s);
        stack<int> val_st;
        char ch;
        char op;
        int val;
        while (iss.peek() != EOF) {
            ch = iss.peek();
            if (ch == ' ') {
                iss >> val;
                val_st.push(val);
            } else {
                iss >> op;
                int val_2 = val_st.top();
                val_st.pop();
                int val_1 = val_st.top();
                val_st.pop();
                if (op == '+') {
                    val = val_1 + val_2;
                } else if (op == '-') {
                    val = val_1 - val_2;
                } else if (op == '*') {
                    val = val_1 * val_2;
                } else if (op == '/') {
                    val = val_1 / val_2;
                }
                val_st.push(val);
            }
        }
        return val_st.top();
    }
};