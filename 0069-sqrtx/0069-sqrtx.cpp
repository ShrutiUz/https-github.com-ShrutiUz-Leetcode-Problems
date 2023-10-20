class Solution {
public:
    int mySqrt(int x) {
        if(x<=1) return x;

        long long ans = 1;

        while(ans*ans<=x){
            
            ans += 1;

            if(ans*ans > x){
                ans -= 1;
                break;
            }
        }

        return ans;

    }
};
