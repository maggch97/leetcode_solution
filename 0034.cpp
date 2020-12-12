class Solution {
public:
    int find(vector<int>&nums,int target){
        int l = 0,r=nums.size();
        while(l<r){
            int mid = l+(r-l)/2;
            if(nums[mid]>=target)r=mid;
            else l=mid+1;
        }
        return l;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = find(nums, target);
        if(l==nums.size() || nums[l]!=target)return {-1,-1};
        return {l, find(nums,target+1)-1};
    }
};