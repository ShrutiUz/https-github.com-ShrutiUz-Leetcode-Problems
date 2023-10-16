class Solution {
public:
    vector<int> getRow(int rowIndex) {

        vector<int>res(rowIndex+1, 1);
        int n = rowIndex+1;

        //from 1 to rowIndex-1
        long long ans = 1;

        for(int i=1; i<=rowIndex-1; i++){
            ans = ans*(n- i);
            ans = ans/i;
            cout<<ans<<" ";
            res[i] = ans;
        }

        return res;
    }
};