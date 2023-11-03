class Solution {
public:
    bool solve(string &s){
        int n = s.size();
        int start = 0, end = n-1;

        while(start <= end){
            if(s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }

        return true;
    }

    bool isPalindrome(string s) {
        //create a new string of letters in lowercase and numbers
        string temp;
        int n = s.size();
        for(int i=0; i<n; i++){
            //how to find if the current element is a letter
            // if it belongs to the range [A, Z] or [a,z]
            char curr = s[i];
            if((curr>= 'a' && curr<='z') || (curr>= 'A' && curr <= 'Z')){
                temp += tolower(curr);
            }
            // how to find if the current element is a number
            // if it belongs to the range [0, 9]
            else if(curr >= '0' && curr <= '9'){
                temp += curr;
            }
        }
        cout<<temp<<endl;
        return solve(temp);
    }
};