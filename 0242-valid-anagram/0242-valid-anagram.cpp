class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }

        vector<int>isPresent(26, 0);

        for(int i=0; i<s.length(); i++){
            isPresent[s[i]-'a']++;
        }

        for(int i=0; i<t.length(); i++){
            isPresent[t[i]-'a']--;
        }

        for(int i=0; i<26; i++){
            if(isPresent[i] != 0){
                return false;
            }
        }

        return true;
    }
};