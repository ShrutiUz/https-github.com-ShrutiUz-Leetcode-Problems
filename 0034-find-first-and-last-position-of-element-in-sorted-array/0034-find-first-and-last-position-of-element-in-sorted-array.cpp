class Solution {
public:

    int solve(vector<int>&nums, int target, bool findLeft){
        int size = nums.size();
        int low = 0;
        int high = size-1;
        int index = -1;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(nums[mid] == target){
                index = mid;
                if(findLeft){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            else if(nums[mid]>target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return index;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int left = solve(nums, target, true);
        int right = solve(nums, target, false);

        if(left<=right){
            return {left, right};
        }
        
        return {-1, -1};
    }
};