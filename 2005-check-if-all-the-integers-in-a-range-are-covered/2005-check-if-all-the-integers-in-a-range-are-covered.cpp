class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int>isCovered(51, 0);
        int n = ranges.size();
        for(int i=0; i<n; i++){
            int start = ranges[i][0];
            int end = ranges[i][1];

            for(int i = start; i<= end; i++){
                isCovered[i] = 1;
            }
        }

        bool flag = true;

        for(int i = left; i<=right; i++){
            if(!isCovered[i]){
                flag = false;
                break;
            }
        }

        return flag;
    }
};