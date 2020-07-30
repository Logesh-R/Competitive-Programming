//1047. Remove All Adjacent Duplicates In String

class Solution {
public:
    Solution(){
        //to speedup the runtime
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
    }
    
    string removeDuplicates(string S) {
        stack<char> stackie;
        int size = S.length();
        
        for(int i=0; i<size; ++i){
            //if empty push to stackie and continue
            if(stackie.empty()){
                stackie.push(S[i]);
                continue;
            } 
            
            //Removing if top is same as current, else push
            if(S[i] == stackie.top()){
                stackie.pop();
            } else {
                stackie.push(S[i]);
            }
        }
        
        //Declared a string with length(size) as return string is stackie size
        //Storing in reverse as we read input reverse in stack 
        size = stackie.size();
        string ret(size--, ' ');
        while(!stackie.empty()){
            ret[size--] = stackie.top();
            stackie.pop();
        }
        
        return ret;
    }
};