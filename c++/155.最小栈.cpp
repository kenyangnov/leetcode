//---------------------Method1: one stack
class MinStack {
   public:
    /** initialize your data structure here. */
    MinStack() {
    }

    void push(int x) {
        if (st.size() == 0) {
            st.push({x, x});
        } else {
            st.push({x, min(x, st.top().second)});
        }
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }

   private:
    stack<pair<int, int>> st;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

//---------------------Method2: two stacks
class MinStack {
   public:
    /** initialize your data structure here. */
    MinStack() {
    }

    void push(int x) {
        if (st.size() == 0) {
            st.push(x);
            minst.push(x);
        } else {
            st.push(x);
            minst.push(min(x, minst.top()));
        }
    }

    void pop() {
        st.pop();
        minst.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minst.top();
    }

   private:
    stack<int> st;
    stack<int> minst;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */