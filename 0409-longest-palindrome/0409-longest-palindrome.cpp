class Solution {
public:
    int longestPalindrome(string s) {
        int ans = 0, odd = 0;
        map<char, int> mp;
        for(auto c: s) mp[c]++;
        for(auto x: mp) {
            if(x.second % 2 == 0) ans += x.second;
            else {
                ans += x.second - 1;
                odd = 1;
            }
        }
        if(odd) ans++;
        return ans;
    }
};