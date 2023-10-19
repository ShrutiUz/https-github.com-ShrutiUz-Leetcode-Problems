class Solution {
public:

    string solve(string &s){
        
        stack<char>st;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '#' && st.size()==0){
                continue;
            }
            else if(s[i] == '#'){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }

        string ss = "";
        while(st.size()!=0){
            char char_s = st.top();
            st.pop();
            ss += char_s;
        }

        reverse(ss.begin(), ss.end());
        return ss;
    }

    bool backspaceCompare(string s, string t) {
        string ss = solve(s);
        string tt = solve(t);

        cout<<ss<<" "<<tt<<endl;

        return ss == tt;
    }
};