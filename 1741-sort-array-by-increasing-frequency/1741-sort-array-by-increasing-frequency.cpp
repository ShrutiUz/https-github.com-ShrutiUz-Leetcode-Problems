class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>> maxHeap;
        for(auto it : mp){
            maxHeap.push({-it.second,it.first});
        }
        vector<int> result;
        while(!maxHeap.empty()){
            int x = maxHeap.top().first;
            for(int i=0;i<abs(x);i++){
                result.push_back(maxHeap.top().second);
            }
            maxHeap.pop();
        }
        return result;
    }
};