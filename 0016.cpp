class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int res = 0;
        int d = INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(i && nums[i]==nums[i-1])continue;
            int l = i+1,r=nums.size()-1;
            if(l<nums.size()-1){
                r=upper_bound(nums.begin()+l+1,nums.end(),target-nums[i]-nums[l])-nums.begin();
                r=min(r,(int)nums.size()-1);
            }
            int f = 0;
            while(l<r){
                int sum = nums[i]+nums[l]+nums[r];
                if(abs(sum-target)<d)res=sum,d=abs(sum-target);
                if(sum>target) r--,f&=1;
                else l++,f&=2;
                if(f==3)break;
            }
        }
        return res;
    }
};