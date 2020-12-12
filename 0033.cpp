class Solution {
public:
    int dfs(vector<int>&nums,int l, int r, int target){
        if(l==r)return target ==nums[l]?l:-1;
        if(nums[l]<nums[r] && (nums[l]>target || nums[r]<target))return -1;
        int mid = l +(r-l)/2;
        int val = dfs(nums,l,mid,target);
        if(val!=-1)return val;
        return dfs(nums,mid+1,r,target);
    }
    int search(vector<int>& nums, int target) {
        if(nums.size()==0)return -1;
        return dfs(nums,0,nums.size()-1,target);
    }
};