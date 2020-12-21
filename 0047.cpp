class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> f(nums.size()+1);
        f[0] = 1;
        for(int i=1;i<f.size();i++)f[i] = f[i-1]*i;
        vector<vector<int>> res;
        for(int i=0;i<f.back();i++){
            vector<int> v;
            vector<bool> flag(nums.size());
            int x = i;
            bool exit = false;
            for(int j=nums.size()-1;j>=0;j--){
                int p = x/f[j];
                x%=f[j];
                for(int k=0;k<nums.size();k++){
                    if(!flag[k]){
                        if(p==0){
                            flag[k] = true;
                            v.push_back(nums[k]);
                            if(k!=0 && nums[k]==nums[k-1] && flag[k-1]==false){
                                exit=true;
                            }
                            break;
                        }else{
                            p--;
                        }
                    }
                }
            }
            if(!exit){
                res.push_back(v);
            }
        }
        return res;
    }
};