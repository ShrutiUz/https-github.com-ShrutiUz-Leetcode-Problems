class Solution {
public:
    int longestValidParentheses(string s) {
        // (()
        //keep two variables, left and right initialised at 0
        //increment left for opening bracket
        //increment right for closing bracket
        //when left == right, store the length as 2*left, update the max length
        //when right>left, that is, when an orphan closing bracket is encountered, set left and right as 0 
        //the above approach is done for left to right motion
        //and is also done for right to left, but the condition is reversed, that is
        //when left>right, means that an orphan opening bracket is encountered, set left and right to 0

        int left = 0, right = 0, n = s.size();
        int maxLen = INT_MIN;

        for(int i=0; i<n; i++){
            if(s[i] == '('){
                left++;
            }
            else if(s[i] == ')'){
                right++;
            }

            if(left == right){
                int currLen = 2*left;
                maxLen = max(maxLen, currLen);
            }
            else if(right>left){
                left = 0;
                right = 0;
            }
        }

        left = 0;
        right = 0;

        for(int i=n-1; i>=0; i--){
            if(s[i] == '('){
                left++;
            }
            else if(s[i] == ')'){
                right++;
            }

            if(left == right){
                int currLen = 2*left;
                maxLen = max(maxLen, currLen);
            }
            else if(left>right){
                left = 0;
                right = 0;
            }
        }

        return maxLen==INT_MIN? 0: maxLen;
    }
};