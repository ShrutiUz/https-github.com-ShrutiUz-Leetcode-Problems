class Solution {
public:
    vector<vector<int>>dp;
    int MOD = 1e9+7;

    int solve(int idx, int steps, int arrLen){
        if(idx == 0 && steps == 0) return 1;
        if(idx<0 || idx>=arrLen || steps==0 || idx>steps) return 0;

        if(dp[idx][steps] != -1) return dp[idx][steps];

        return dp[idx][steps] =( ((solve(idx+1, steps-1, arrLen))%MOD + (solve(idx-1, steps-1,arrLen)))%MOD + (solve(idx, steps-1, arrLen)))%MOD;

    }

    int numWays(int steps, int arrLen) {
        dp.resize(steps/2+1, vector<int>(steps+1, -1));
        return solve(0, steps, arrLen);
    }
};