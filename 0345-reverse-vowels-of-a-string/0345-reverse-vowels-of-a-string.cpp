class Solution {
public:

    set<char>storeVowel = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

    string reverseVowels(string s) {

        vector<char>vowel;

        for(int i=0; i<s.size(); i++){
            if(storeVowel.find(s[i]) != storeVowel.end()){
                vowel.push_back(s[i]);
            }
        }

        int idx = 0;

        for(int i=s.size()-1; i>=0; i--){
            if(storeVowel.find(s[i]) != storeVowel.end()){
                s[i] = vowel[idx++];
            }
        }

        return s;
    }
};