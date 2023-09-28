class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;

        while(low<=high){
            if(nums[low]%2!=0 && nums[high]%2!=0){
                //odd and odd 
                high--;
            }
            else if(nums[low]%2==0 && nums[high]%2!=0){
                //even and odd
                low++;
                high--;
            }
            else if(nums[low]%2==0 && nums[high]%2==0){
                //even and even
                low++;
            }
            else if(nums[low]%2!=0 && nums[high]%2==0){
                //odd and even
                swap(nums[low], nums[high]);
                low++;
                high--;
            }
        }

        return nums;
    }
};