class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>  res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i && nums[i]==nums[i-1])continue;
            int l=i+1,r=nums.size()-1;
            while(l<r){
                if(l-1!=i &&nums[l]==nums[l-1]){l++;continue;}
                if(r+1!=nums.size()&&nums[r]==nums[r+1]){r--;continue;}
                int sum = nums[i]+nums[l]+nums[r];
                if(sum==0){res.push_back({nums[i],nums[l],nums[r]});l++;}
                else if(sum<0)l++;
                else r--;
            }
        }
        return res;
    }
};