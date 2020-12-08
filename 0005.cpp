class Solution {
public:
    string longestPalindrome(string s) {
        string newS = "#";
        for (const auto &c:s) {
            newS += c;
            newS += "#";
        }
        vector<int> dp(newS.size());
        dp[0] = 1;
        int maxR = 0;
        int mid = 0;
        int result = 0;
        int resultPos = 0;
        for (int i = 1; i < dp.size() - 1; i++) {
            if (i <= maxR) {
                dp[i] = min(dp[2 * mid - i], maxR - i + 1);
            }
            while (dp[i] + i < dp.size() && i - dp[i] >= 0 && newS[dp[i] + i] == newS[i - dp[i]]) {
                dp[i]++;
            }
            if (i + dp[i] - 1 >= maxR) {
                mid = i;
                maxR = i + dp[i] - 1;
            }
            if (result < dp[i]) {
                result = dp[i];
                resultPos = i;
            }
        }
        int l = (resultPos - dp[resultPos] + 1) / 2;
        int len = result - 1;
        return s.substr(l, len);
    }
};