class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n =nums.size();
        int e = 0;
        int o = 1;

        while(e<n && o<n){
            if(nums[e]%2==0 && nums[o]%2==1){
                //even idx - even
                //odd idx - odd
                e+=2;
                o+=2;
            }
            else if(nums[e]%2==1 && nums[o]%2==0){
                //even idx - odd
                //odd idx - even
                swap(nums[e], nums[o]);
                e+=2;
                o+=2;
            }
            else if(nums[e]%2==0 && nums[o]%2==0){
                //even idx - even
                //odd idx -even
                e +=2;
            }
            else{
                o +=2;
            }

            // for(int i=0; i<n; i++){
            //     cout<<nums[i]<<" ";
            // }
            // cout<<endl;
        }
        return nums;
    }
};