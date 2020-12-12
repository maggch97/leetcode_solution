class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())return 0;
        int pre = nums[0]-1;
        int len = 0;
        for(const auto&x:nums){
            if(x!=pre){
                nums[len++] =x;
                pre=x;
            }
        }
        return len;
    }
};