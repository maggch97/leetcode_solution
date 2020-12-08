class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int count[CHAR_MAX + 1] = {0};
        int result = 0;
        int l = 0;
        for (int i = 0; i < s.length(); i++) {
            if (++count[s[i]] > 1) {
                while (count[s[i]] > 1) {
                    count[s[l++]]--;
                }
            }
            result = max(i - l + 1, result);
        }
        return result;
    }
};