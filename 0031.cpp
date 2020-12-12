class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()==0)return;
        int r = nums.size()-1;
        while(r!=0 && nums[r-1]>=nums[r])r--;
        if(r==0){
            sort(nums.begin(),nums.end());
            return;
        }
        int mi = INT_MAX;
        for(int i=r;i<nums.size();i++){
            if(nums[i]>nums[r-1])mi=min(mi,nums[i]);
        }
        for(int i=r;i<nums.size();i++){
            if(nums[i]==mi){
                swap(nums[i],nums[r-1]);
                break;
            }
        }
        sort(nums.begin()+r, nums.end());
    }
};