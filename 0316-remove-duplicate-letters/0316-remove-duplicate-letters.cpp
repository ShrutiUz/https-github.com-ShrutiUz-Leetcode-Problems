class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>lastIndex(26, 0);

        for(int i=0; i<s.size(); i++){
            lastIndex[s[i] - 'a'] = i;
        }

        vector<bool>seen(26, false);
        stack<char>st;

        for(int i=0; i<s.size(); i++){
            char curr = s[i] - 'a';
            if(seen[curr]) continue;

            while(st.size()>0 && s[i]<st.top() && i<lastIndex[st.top() - 'a']){
                seen[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(s[i]);
            seen[curr] = true;
        }

        string temp = "";

        while(st.size()){
            temp += st.top();
            st.pop();
        }

        reverse(temp.begin(), temp.end());

        return temp;
    }
};