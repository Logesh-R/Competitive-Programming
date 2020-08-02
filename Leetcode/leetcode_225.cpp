//225. Implement Stack using Queues

class MyStack {
    queue<int> que1, que2;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        que2.push(x);
        while(!que1.empty()){
            que2.push(que1.front());
            que1.pop();
        }
        
        swap(que1, que2);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(que1.empty())
            return -1;
        
        int temp = que1.front();
        que1.pop();
        
        return temp;        
    }
    
    /** Get the top element. */
    int top() {
        if(que1.empty())
            return -1;
        
        return que1.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return que1.empty();
    }
};