class Solution {
public:

    void revStr(string &str, int s, int e){
        if(s<0 || e>str.size() || s>e){
            return;
        }

        while(s<=e){
            char ch = str[s];
            str[s] = str[e];
            str[e] = ch;
            s++;
            e--;
        }

        return;
    }

    string reverseWords(string s) {
        int n = s.size();
        int prev = 0;
        int next = 0;

        for(int i=0; i<n; i++){
            if(s[i] == ' ' || i==n-1){

                if(i==n-1){
                    next = i;
                }
                else{
                    next = i-1;
                }
                
                // revStr(s, prev, next);
                reverse(s.begin()+prev, s.begin()+next+1);

                prev = i+1;
            }
        }

        return s;
    }
};