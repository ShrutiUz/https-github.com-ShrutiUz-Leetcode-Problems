class Solution {
public:
    int countHomogenous(string s) {
        int mod = 1e9+7;
        int ans = 0, count = 0;

        int siz = s.length();

        for(int i=0; i<siz; i++){
            if(i>0 && s[i] == s[i-1]){
                count++;
            }
            else{
                count = 1;
            }
            ans = (ans+count)%mod;
        }

        return ans;

    }
};