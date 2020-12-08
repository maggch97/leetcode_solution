class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<pair<int, int>> numsWithPos;
        for (int i = 0; i < nums.size(); i++) {
            numsWithPos.push_back({nums[i], i});
        }
        sort(numsWithPos.begin(), numsWithPos.end());
        for (int i = 0; i < numsWithPos.size(); i++) {
            int l = i + 1, r = numsWithPos.size();
            while (l != r) {
                int mid = (l + r) / 2;
                if (numsWithPos[i].first + numsWithPos[mid].first >= target) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            if (l != numsWithPos.size() && numsWithPos[i].first + numsWithPos[l].first == target) {
                return {numsWithPos[i].second, numsWithPos[l].second};
            }
        }
        return {};
    }
};