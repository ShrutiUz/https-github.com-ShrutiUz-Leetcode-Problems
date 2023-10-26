class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool>dp(n, false);
        dp[n-1] = true;

        for(int i=n-2; i>=0; i--){
            if(nums[i] == 0){
                dp[i] = false;
                continue;
            }

            int flag = 0;

            int steps = nums[i];
            for(int idx = 1; idx<=steps; idx++){
                if(idx+i<n && dp[idx+i]){
                    dp[i] = true;
                    flag = 1;
                    break;
                }
            }

            if(flag == 1){
                continue;
            }

            dp[i] = false;
            
        }

        return dp[0];
    }
};