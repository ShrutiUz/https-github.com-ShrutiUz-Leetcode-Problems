class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int>mp;

        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }

        priority_queue<pair<int,int>>pq;

        for(auto it: mp){
            pq.push({-it.second, it.first});
        }

        vector<int>res;

        while(pq.size() != 0){
            int x = pq.top().first;
            int y = pq.top().second;
            pq.pop();

            for(int i=1; i<=abs(x); i++){
                res.push_back(y);
            }
        }

        // reverse(res.begin(), res.end());

        return res;
    }
};