class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //we need to use min heap
        // to store the kth largest element

        priority_queue<int, vector<int>, greater<int>>pq;

        int numsSize = nums.size();

        for(int i=0; i<numsSize; i++){
            pq.push(nums[i]);

            if(pq.size()>k){
                pq.pop();
            }
        }

        return pq.top();

    }
};