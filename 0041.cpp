/*
while(a[i]<n && a[i]>=1 && a[i]!= a[a[i]-1])swap(a[i], a[a[i]-1]);
这一步时间复杂度看起来不好分析，但是如果我们把数字 x 放到 nums[x-1] 看做是一次操作。
那么这个while循环每次都会完成这样一个操作，并且因为有 a[i]!= a[a[i]-1] 限制所以一个x只会做一次操作。
那么显然最多n个数字，就只会做n次操作
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        auto&a=nums;
        int n = a.size();
        if(n==0)return 1;
        for(int i=0;i<n;i++){
            while(a[i]<n && a[i]>=1 && a[i]!= a[a[i]-1])swap(a[i], a[a[i]-1]);
        }
        for(int i=0;i<n;i++){
            if(a[i]!=i+1)return i+1;
        }
        return n+1;
    }
};