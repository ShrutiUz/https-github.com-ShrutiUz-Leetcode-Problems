class Solution {
public:
    int longestValidParentheses(string s) {
        //two stack approach
        //stack 1 - stores the opening bracket
        //stack 2 - stores the problematic indices

        stack<char>ch;
        stack<int>st;

        st.push(-1);
        int n  = s.size();

        int maxLen = INT_MIN;

        for(int i=0; i<n; i++){
            if(s[i] == '('){
                ch.push('(');
                st.push(i);
            }
            else{
                if(ch.size() != 0 && ch.top() == '('){
                    ch.pop();
                    st.pop();
                    maxLen = max(maxLen, i-st.top());
                }
                else{
                    st.push(i);
                }
            }
        }

        return maxLen == INT_MIN ? 0 : maxLen;
    }
};