class Solution {
public:
    void dfs(vector<string> &res, string prefix,int l,int r){
        if(l==0 && r==0){
            res.push_back(prefix);
            return;
        }
        if(l!=0)dfs(res,prefix+"(",l-1,r);
        if(l!=r && r!=0)dfs(res,prefix+")",l,r-1);
        
    }
    vector<string> generateParenthesis(int n) {
        if(n==0)return {};
         vector<string> res;
        dfs(res,"",n,n);
        return res;
    }
};