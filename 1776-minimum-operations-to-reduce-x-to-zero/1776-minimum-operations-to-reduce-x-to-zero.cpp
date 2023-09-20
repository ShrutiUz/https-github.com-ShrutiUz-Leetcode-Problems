class Solution {
public:
    int minOperations(vector<int>& nums, int x) {

        int numsSize = nums.size();

        unordered_map<int,int>mp;

        mp[0] = -1;

        int sum = 0;

        for(int i=0; i<numsSize; i++){
            sum += nums[i];
            mp[sum] = i;
        }

        if(x>sum) return -1;

        int target = sum - x;
        int maxLen = INT_MIN;
        sum = 0;

        for(int i=0; i<numsSize; i++){
            sum += nums[i];

            int currSum = sum - target;

            if(mp.find(currSum) != mp.end()){
                int idx = mp[currSum];
                maxLen = max(maxLen, i - idx);
            }
        }

        return maxLen == INT_MIN ? -1 :numsSize - maxLen;

    }
};