class Solution {
public:
    int reverse(int x) {
        // 不用CLion格式化，代码逐渐飘逸，我的青春又回来了
        if(x==0)return 0;
        int y = x/abs(x);
        x=abs(x);
        long long res = 0;
        while(x!=0){
            res = res*10 + x%10;
            x/=10;
        }
        return res*y == (int)res*y ? res*y:0;
    }
};