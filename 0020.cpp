class Solution {
public:
    bool isValid(string s) {
        map<char,char> p = {{'(',')'},{'[',']'},{'{','}'}};
        stack<char> stk;
        for(const auto &c:s){
            if(c=='(' || c=='{' || c=='['){
                stk.push(c);
            }else{
                if(stk.empty() || p[stk.top()]!=c){
                    return false;
                }
                stk.pop();
            }
        }
        return stk.empty();
    }
};