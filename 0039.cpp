class Solution {
public:
    void dfs(vector<int>& nums, vector<vector<int>> &res, vector<int>& pre, int idx,int target){
        if(target == 0){
            res.push_back(pre);
            return;
        }
        if(idx==-1)return ;
        for(int i=0;;i++){
            if(target<i*nums[idx])break;
            dfs(nums,res,pre,idx-1,target-i*nums[idx]);
            pre.push_back(nums[idx]);
        }
        while(!pre.empty() && pre.back()==nums[idx])pre.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
         vector<vector<int>> res;
        sort(candidates.begin(),candidates.end());
        vector<int> pre;
        dfs(candidates, res,pre,candidates.size()-1,target);
        return res;
    }
};