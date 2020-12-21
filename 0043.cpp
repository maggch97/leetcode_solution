class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> res(num1.size()*num2.size()+1);
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        for(int i=0;i<num1.size();i++){
            for(int j=0;j<num2.size();j++){
                res[i+j]+=(num1[i]-'0')*(num2[j]-'0');
            }
        }
        for(int i=0;i<res.size();i++){
            if(res[i]>=10){
                res[i+1]+=res[i]/10;
                res[i]%=10;
            }
        }
        while(!res.empty() && res.back()==0)res.pop_back();
        if(res.empty())return "0";
        string s;
        for(const auto x: res){
            s+=x+'0';
        }
        reverse(s.begin(),s.end());
        return s;
    }
};