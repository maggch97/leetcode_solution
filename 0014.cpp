class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())return"";
        int res = 0;
        for(;;){
            for(int i=0;i<strs.size();i++){
                if(strs[i].size()<=res)return strs[0].substr(0,res);
                if(strs[i][res]!=strs[0][res])return strs[0].substr(0,res);
            }
            res++;
        }
    }
};