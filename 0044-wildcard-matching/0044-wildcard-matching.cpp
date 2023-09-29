class Solution {
public:

    bool allStars(string &p, int j){
        for(int i=j; i>=0; i--){
            if(p[i] != '*'){
                return false;
            }
        }
        return true;
    }

    bool solve(string &s, string &p, int i, int j, vector<vector<int>>&dp){
        if(i<0 && j<0) return true;
        if(j<0) return false;
        if(i<0) return allStars(p, j);

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == p[j]){
            return dp[i][j] =  solve(s, p, i-1, j-1, dp);
        }
        else if(p[j] == '?'){
            return dp[i][j] = solve(s, p, i-1, j-1, dp);
        }
        else if(p[j] == '*'){
            return dp[i][j] = solve(s,p, i-1,j, dp) || solve(s,p, i, j-1, dp);
        }
        else{
            return dp[i][j] = false;
        }


    }

    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return solve(s, p, n-1, m-1, dp);
    }
};