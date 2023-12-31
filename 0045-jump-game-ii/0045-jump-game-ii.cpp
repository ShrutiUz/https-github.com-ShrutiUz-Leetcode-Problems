class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, INT_MAX-1);
        dp[n-1] = 0;

        for(int i=n-2; i>=0; i--){
            int steps = nums[i];
            for(int j=1; j<=steps; j++){
                if(i+j<n){
                    dp[i] = min(dp[i], 1 + dp[i+j]);
                }
            }
        }

        return dp[0];
    }
};