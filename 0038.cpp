class Solution {
public:
    string countAndSay(int n) {
        if(n==1)return "1";
        string say = countAndSay(n-1);
        string res = "";
        char pre = -1;
        int len = 0;
        for(int i=0;i<say.size();i++){
            if(say[i]==pre)len++;
            else{
                if(pre!=-1){
                    res+=(char)('0'+len);
                    res+=pre;
                }
                pre = say[i];
                len=1;
            }
        }
        res+=(char)('0'+len);
        res+=pre;
        return res;
    }
};