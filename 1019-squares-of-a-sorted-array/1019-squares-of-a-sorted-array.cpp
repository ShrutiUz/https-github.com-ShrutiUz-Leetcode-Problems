class Solution {
public:

    vector<int> solve(vector<int>&nums){
        int n = nums.size();
        int idx;
        vector<int>temp;

        for(int i=0; i<n; i++){
            if(nums[i]>=0){
                idx = i;
                break;
            }
        }

        int left = idx-1;
        int right = idx;

        while(left>=0 && right<n){
            if(nums[left]*nums[left] <= nums[right]*nums[right]){
                temp.push_back(nums[left]*nums[left]);
                left--;
            }
            else{
                temp.push_back(nums[right]*nums[right]);
                right++;
            }
        }

        while(left>=0){
            temp.push_back(nums[left]*nums[left]);
            left--;
        }

        while(right<n){
            temp.push_back(nums[right]*nums[right]);
            right++;
        }

        return temp;
        
        
    }

    vector<int> sortedSquares(vector<int>& nums) {
        return solve(nums);
    }
};