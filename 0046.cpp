class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> f(nums.size()+1);
        f[0] = 1;
        for(int i=1;i<f.size();i++)f[i] = f[i-1]*i;
        vector<vector<int>> res;
        for(int i=0;i<f.back();i++){
            vector<int> v;
            vector<bool> flag(nums.size());
            int x = i;
            for(int j=nums.size()-1;j>=0;j--){
                int p = x/f[j];
                x%=f[j];
                for(int k=0;k<nums.size();k++){
                    if(!flag[k]){
                        if(p==0){
                            flag[k] = true;
                            v.push_back(nums[k]);
                            break;
                        }else{
                            p--;
                        }
                    }
                }
            }
            res.push_back(v);
        }
        return res;
    }
};