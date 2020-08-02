//155. Min Stack

struct MStack{
    int value, Min;
};

class MinStack {
    stack<MStack> stackie;
public:
    void push(int x) {
        int temp = x;
        if(!stackie.empty() && stackie.top().Min < x)
            temp = stackie.top().Min;
        
        struct MStack pushElement = {x, temp};
        stackie.push(pushElement);
    }
    
    void pop() {
        if(!stackie.empty()) stackie.pop();
    }
    
    int top() {
        return stackie.top().value;
    }
    
    int getMin() {
        return stackie.top().Min;
    }
};