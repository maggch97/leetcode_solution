class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())return {};
        map<int,vector<char>> m;
        m[2]={'a','b','c'};
        m[3]={'d','e','f'};
        m[4]={'g','h','i'};
        m[5]={'j','k','l'};
        m[6]={'m','n','o'};
        m[7]={'p','q','r','s'};
        m[8]={'t','u','v'};
        m[9]={'w','x','y','z'};
         vector<string> res;
        int sum = 1;
        for(int i=0;i<digits.size();i++){
            sum*=m[digits[i]-'0'].size();
        }
        res.resize(sum);
        int p = 1;
        for(int i=0;i<digits.size();i++){
            int block=sum/p;
            for(int j=0;j<sum;j++){
                int bb = block/m[digits[i]-'0'].size();
                res[j]+= m[digits[i]-'0'][(j%block)/bb];
            }
            p*=m[digits[i]-'0'].size();
        }
        return res;
    }
};