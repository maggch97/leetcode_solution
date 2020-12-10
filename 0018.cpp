class Solution {
public:
    vector<vector<int>> fourSum(vector<int> nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i && nums[i - 1] == nums[i])continue;
            for (int j = i + 1; j < nums.size(); j++) {
                if (j != i + 1 && nums[j] == nums[j - 1])continue;
                int r = nums.size() - 1;
                int t = target - nums[i] - nums[j];
                for (int l = j + 1; l < nums.size(); l++) {
                    if (l != j + 1 && nums[l] == nums[l - 1])continue;
                    while (r > l && r + 1 != nums.size() && nums[r + 1] == nums[r])r--;
                    while (r > l && nums[l] + nums[r] > t)r--;
                    if (l == r)break;
                    if (nums[l] + nums[r] == t) {
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                    }
                }
            }
        }
        return res;
    }
};
