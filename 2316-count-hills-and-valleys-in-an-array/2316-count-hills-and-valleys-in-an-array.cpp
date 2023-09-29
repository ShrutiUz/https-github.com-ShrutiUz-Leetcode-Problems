class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int last = nums[0];

        int hills = 0, valleys = 0;

        for(int i=1; i<n-1; i++){
            if(nums[i] == last){
                continue;
            }
            if(nums[i]>last && nums[i]>nums[i+1]){
                hills++;
                last = nums[i];
            }
            else if(nums[i]<last && nums[i]<nums[i+1]){
                valleys++;
                last = nums[i];
            }
        }
        return hills+valleys;
    }
};