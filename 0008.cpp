class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        while(i<s.size()&&s[i]==' ')i++;
        if(i==s.size())return 0;
        int flag = 1;
        if(s[i]=='+'){
            flag*=1;
            i++;
        }else if(s[i]=='-'){
            flag*=-1;
            i++;
        }
        int j;
        long long num=0;
        for(j=i;j<s.size();j++){
            if(s[j]>='0' && s[j]<='9'){
                num = num*10+s[j]-'0';
            }else{
                break;
            }
            if(num>=INT_MAX)break;
        }
        if(j==i)return 0;
        if(flag*num<=INT_MIN)return INT_MIN;
        if(flag*num>=INT_MAX)return INT_MAX;
        return flag*num;
    }
};