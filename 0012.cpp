class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int,string>> v = {{1,"I"},{4,"IV"},{5,"V"},{9,"IX"},{10,"X"},{40,"XL"},{50,"L"},{90,"XC"},{100,"C"},
                                      {400,"CD"},{500,"D"},{900,"CM"},{1000,"M"}};
        string res;
        auto it = v.end()-1;
        while(num){
            while(it->first>num)it--;
            res+=it->second;
            num-=it->first;
        }
        return res;
    }
};