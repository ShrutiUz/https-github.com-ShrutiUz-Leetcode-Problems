class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int>even;
        vector<int>odd;

        int n = nums.size();

        for(int i=0; i<n; i++){
            if(nums[i]%2){
                //odd
                odd.push_back(nums[i]);
            }
            else{
                even.push_back(nums[i]);
            }
        }

        int cnt_even = even.size();
        int cnt_odd = odd.size();

        for(int i=0; i<cnt_even; i++){
            nums[i] = even[i];
        }

        for(int i=0; i<cnt_odd; i++){
            nums[cnt_even + i] = odd[i];
        }

        return nums;

        
    }
};