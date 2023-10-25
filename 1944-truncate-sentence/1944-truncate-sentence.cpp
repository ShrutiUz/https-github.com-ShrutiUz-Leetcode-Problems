class Solution {
public:
    string truncateSentence(string s, int k) {
        string ans = "";

        int i = 0, count = 0;

        while(i<s.size() && count<k){
            if(s[i] == ' '){
                count++;
                if(count == k){
                    return ans;
                }
                ans += ' ';
            }
            else{
                ans += s[i];
            }
            i++;
        }
        return ans;
    }

};