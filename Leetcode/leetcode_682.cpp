//682. Baseball Game

class Solution {
public:
    int calPoints(vector<string>& ops) {
        
        stack<int> stackie;
        int temp, last, slast, sum = 0;
        
        for(string s:ops){
            if(s == "C"){
                //Cancelling the last round by popping from stack
                if(!stackie.empty()){
                    sum -= stackie.top();
                    stackie.pop();
                }
            } else if(s == "D") {
                //Doubling the last rount value on "D"
                if(!stackie.empty()){
                    temp = stackie.top();
                    stackie.push(temp*2);
                    sum += (temp*2);
                }
            } else if(s == "+"){
                //Push the last and second last rounds sum on "+"
                last = stackie.top(); stackie.pop();
                slast = stackie.top();
                stackie.push(last);
                sum += (last + slast);
                stackie.push(last + slast);
            } else {
                //on Integer just pushing after converting to int
                temp = stoi(s);
                sum += temp;
                stackie.push(temp);
            }
        }
        
        return sum;
    }
};