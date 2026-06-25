class MinStack {
public:
    map<int , int> Mp;
    stack<int> Stack;
    MinStack() {
        
    }
    
    void push(int val) {
        Stack.push(val);
        Mp[val]+=1;
    }
    
    void pop() {       
        
        Mp[Stack.top()]--;
        if(Mp[Stack.top()] == 0){
            Mp.erase(Stack.top());
        }
        Stack.pop();
    }
    
    int top() {
        return Stack.top();
    }
    
    int getMin() {
        for(auto s : Mp){
            return s.first;
        }
        return 0;
    }
};
