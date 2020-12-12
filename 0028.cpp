class Solution {
public:
    int strStr(string haystack, string needle) {
        auto & s = haystack;
        auto & p  =needle;
        if(p.empty())return 0;
        vector<int> next(p.size(), -1);
        for (int i = 1; i < p.size(); i++) {
            int k = i - 1;
            while (k != -1 && p[next[k] + 1] != p[i])k = next[k];
            int nxtk = k == -1 ? -1 : next[k];
            if (p[nxtk + 1] == p[i])next[i] = nxtk + 1;
        }
        int now = -1;
        for (int i = 0; i < s.length(); i++) {
            while (now != -1 && s[i] != p[now + 1])now = next[now];
            if (p[now + 1] == s[i])now++;
            else now = -1;
            if (now == p.size() - 1)return i - p.size()+1;
        }
        return -1;
    }
};