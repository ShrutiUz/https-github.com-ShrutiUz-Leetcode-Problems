class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        // odd indices - decreasing order
        // even indices - increasing order

        //since the range is very small, we can use counting sort
        int k = 100;
        int count[k+1];
        
        for(int i=0; i<=k; i++){
            count[i] = 0;
        }

        for(int i=0; i<nums.size(); i+=2){
            int key = nums[i];
            count[key]++;
        }

        int j=0;
        for(int i=0; i<=k; i++){
            while(count[i]>0){
                nums[j] = i;
                count[i]--;
                j = j+2;
            }
        }

        for(int i=1; i<nums.size(); i+=2){
            int key = nums[i];
            count[key]++;
        }

        j=1;
        for(int i=k; i>=0; i--){
            while(count[i]>0){
                nums[j] = i;
                count[i]--;
                j = j+2;
            }
        }
        
        return nums;


    }
};