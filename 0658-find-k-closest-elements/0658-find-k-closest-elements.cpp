class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        //we can solve this problem by using a maxHeap
        // this heap will store the (abs(arr[i])-x, arr[i])
        // the k elements having the smallest abs difference 
        // will be the k closest

        //define maxHeap of pair<int,int>
        priority_queue<pair<int,int>>pq;

        for(int i=0; i<arr.size(); i++){
            int diff = abs(arr[i]-x);
            pq.push({diff, arr[i]});

            if(pq.size()>k){
                pq.pop();
            }
        }

        vector<int>res;

        while(!pq.empty()){
            int num = pq.top().second;
            pq.pop();
            res.push_back(num);
        }

        sort(res.begin(), res.end());

        return res;
    }
};