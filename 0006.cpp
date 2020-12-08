class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)return s;
        vector<string> result(numRows);
        int direction = 0;
        int r = 0, c = 0;
        int idx = 0;
        do {
            while (result[r].length() < c) {
                result[r] += ' ';
            }
            result[r] += s[idx++];
            if (r == 0) {
                direction = 0;
            } else if (r == result.size() - 1) {
                direction = 1;
            }
            if (direction == 0) {
                r++;
            } else {
                r--;
                c += 2;
            }
        } while (idx != s.size());
        string resultStr;
        string res;
        // 一开始看错题目了，以为要输出那个n行的东西。之后再改个优美点的吧
        for (const auto &str : result) {
            resultStr.append(str).append("\n");
            for (const auto &c:str) {
                if (c != ' ') {
                    res += c;
                }
            }
        }
        return res;
    }
};