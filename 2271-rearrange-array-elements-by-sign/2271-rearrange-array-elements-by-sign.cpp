class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int positive_idx = 0;
        int negative_idx = 1;

        int n = nums.size();

        vector<int>res(n,0);

        for(int i=0; i<n; i++){
            if(nums[i]>0){
                res[positive_idx] = nums[i];
                positive_idx += 2;
            }
            else{
                res[negative_idx] = nums[i];
                negative_idx += 2;
            }
        }

        return res;
    }
};