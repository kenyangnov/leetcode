/*
v0:自己写的，有多处错误，最终未实现
class MinStack {
private:
    vector<int> data;
    int min;
    int size;	//size有加有减，在pop中没有减
public:
    MinStack() {
        size=0;
    }
    
    void push(int x) {
        data.push_back(x);
        if(size==0){
            min=x;
        }
        min = x<min?x:min;
        size++;
    }
    
    void pop() {
        if(!data.empty()){
            data.pop_back();
        }
    }
    
    int top() {
        return data.back();
    }
    
    int getMin() {
        return min;
    }
};
*/
//v1:两个栈实现
class MinStack_v1 {
private:
    stack<int> s1; //存数据
    stack<int> s2; //存当前最小值
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s1.push(x);
        if(s2.empty()||x<=getMin()){ //注意此处的等于
            s2.push(x);
        }
    }
    
    void pop() {
        if(s1.top()==getMin()){
            s2.pop();
        }
        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
};
//v2:可以用一个栈实现，加一个变量存储当前的最小值，每次push时，如果新push进来的元素比当前的最小值还要小，将当前的最小值与要push的数据一起push（一共push两次），再修改最小值；pop时，如果正好pop出最小的元素，那么下一个最小的元素一定就在栈顶，赋值后再pop出去（pop两次）。
//via:https://blog.csdn.net/SoulOH/article/details/81268064
class MinStack_v2 {
private:
    stack<int> data;
    int min;
public:
    /** initialize your data structure here. */
    MinStack() {
        min = INT_MAX;
    }
    
    void push(int x) {
        if(x<=min){
            data.push(min);
            data.push(x);
            min=x;
        }
        else{
            data.push(x);
        }
    }
    
    void pop() {
        if(data.top()==min){
            data.pop();
            min=data.top();
            data.pop();
        }
        else{
            data.pop();
        }
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return min;
    }
};