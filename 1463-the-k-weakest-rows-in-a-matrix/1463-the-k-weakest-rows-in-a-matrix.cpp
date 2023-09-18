class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        //map - (row, number of 1)
        // sort the map based on the second index , ie the value, ie the number of 1s
        // in ascending order
        // if number of 1s is same for two rows, sort in ascending order of rows

        int n = mat.size();
        int m = mat[0].size();
        vector<pair<int,int>>v;

        for(int i=0; i<n; i++){
            int count = 0;
            for(int j=0; j<m; j++){
                if(mat[i][j] == 1)
                count++;
            }
            v.push_back({count,i});
        }

        sort(v.begin(), v.end());

        vector<int>res;

        for(int i=0; i<k; i++){
            res.push_back(v[i].second);
        }

        return res;


    }
};