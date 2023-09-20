class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        unordered_map<int,int>mp;
        int sum = 0;
        mp[0] = -1;

        for(int i =0; i<n; i++){
            sum += nums[i];
            mp[sum] = i;
        }

        if(x>sum) return -1;

        int target = sum - x;
        sum = 0;
        int maxLen = INT_MIN;

        for(int i=0; i<n; i++){
            sum += nums[i];

            int currSum = sum - target;

            if(mp.find(currSum) != mp.end()){
                int idx = mp[currSum];
                maxLen = max(maxLen, i - idx);
            }
        }

        return maxLen == INT_MIN?  -1 :  n- maxLen;
    }
};