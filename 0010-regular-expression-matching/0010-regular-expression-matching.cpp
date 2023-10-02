class Solution {
public:
    bool solve(string &s, string &p, int i, int j){
        int n1 = s.size(), n2 = p.size();

        if(j==n2) return i==n1;

        if(p[j+1] == '*'){
            if(solve(s, p, i, j+2) || (i<n1 && (p[j] == '.' || s[i] == p[j]) && solve(s,p, i+1, j))){
                return true;
            }
        }
        else if( i<n1 && (p[j] == '.' || s[i] == p[j]) && solve(s, p, i+1, j+1)){
            return true;
        }

        return false;
    }

    bool isMatch(string s, string p) {
        return solve(s, p, 0, 0);
    }
};