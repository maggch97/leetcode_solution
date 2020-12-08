class Solution {
public:
    int romanToInt(string s) {
        vector<pair<int,string>> v = {{1,"I"},{4,"IV"},{5,"V"},{9,"IX"},{10,"X"},{40,"XL"},{50,"L"},{90,"XC"},{100,"C"},
                                      {400,"CD"},{500,"D"},{900,"CM"},{1000,"M"}};
        auto it = v.end()-1;
        int res = 0;
        for(int i=0;i<s.size();){
            while(s.find(it->second,i)!=i)it--;
            res+=it->first;
            i+=it->second.size();
        }
        return res;
    }
};