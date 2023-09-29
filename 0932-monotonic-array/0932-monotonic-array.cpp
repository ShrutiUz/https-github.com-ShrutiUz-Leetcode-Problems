class Solution {
public:

    bool checkDec(vector<int>&nums){
        int n = nums.size();

        for(int i=1; i<n; i++){
            if(nums[i]<=nums[i-1]){
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }

    bool checkInc(vector<int>&nums){
        int n = nums.size();

        for(int i=1; i<n; i++){
            if(nums[i]>=nums[i-1]){
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }

    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return true;
        
        bool inc = checkInc(nums);
        bool dec = checkDec(nums);

        return inc||dec;
    }
};