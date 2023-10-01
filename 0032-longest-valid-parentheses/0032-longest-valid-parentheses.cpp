class Solution {
public:
    int longestValidParentheses(string s) {

        stack<int>st;
        int n = s.size();

        for(int i=0; i<n; i++){
            if(s[i] == '('){
                st.push(i);
            }
            else{
                if(st.size()){
                    s[st.top()] = '*';
                    s[i] = '*';
                    st.pop();
                }
            }
        }

        int maxCount = 0;
        int res = 0;

        for(int i=0; i<n; i++){
            if(s[i] == '*'){
                res++;
            }
            else{
                maxCount = max(maxCount, res);
                res = 0; 
            }
        }

        //we are again comparing the maxCount and res because assume for this case, ((), the loop will go out of bound and we wont be able to update maxCount, therefore we return the maximum of res and maxCount
        return max(maxCount, res);
    }
};