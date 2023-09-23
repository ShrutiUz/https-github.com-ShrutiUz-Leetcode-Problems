class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        priority_queue<pair<int,int>>pq;

        for(int i=0; i<n; i++){
            pq.push({abs(x-arr[i]), arr[i]});
            if(pq.size()>k){
                pq.pop();
            }
        }

        vector<int>res;

        while(pq.empty() == false){
            int x = pq.top().second;
            pq.pop();
            res.push_back(x);
        }

        sort(res.begin(), res.end());

        return res;
    }
};