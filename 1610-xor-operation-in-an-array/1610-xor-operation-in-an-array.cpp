class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int>nums(n);

        nums[0] = start;
        int res = nums[0];

        for(int i=1; i<n; i++){
            nums[i] = start + 2*i;
            res ^= nums[i];
        }

        return res;
    }
};