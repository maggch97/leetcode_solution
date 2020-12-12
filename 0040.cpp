class Solution {
public:
    vector<vector<int>> res;
    vector<int> pre;
    vector<int> nums;
    vector<int> limit;
    void dfs(int idx,int target){
        if(target==0){
            res.push_back(pre);
            return;
        }
        if(idx>=nums.size())return;
        for(int i=0;i<=limit[idx];i++){
            if(i*nums[idx]>target)break;
            dfs(idx+1, target-i*nums[idx]);
            pre.push_back(nums[idx]);
        }
        while(!pre.empty() && pre.back()==nums[idx])pre.pop_back();
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        map<int,int> m;
        for(int i=0;i<candidates.size();i++){
            m[candidates[i]]++;
        }
        for(const auto& it:m){
            nums.push_back(it.first);
            limit.push_back(it.second);
        }
        dfs(0,target);
        return res;
    }
};