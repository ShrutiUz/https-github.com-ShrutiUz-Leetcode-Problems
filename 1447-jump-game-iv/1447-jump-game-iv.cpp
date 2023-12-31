class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int, vector<int>>mp;
        
        for(int i=0; i<n; i++){
            mp[arr[i]].push_back(i);
        }

        vector<bool>vis(n, false);
        queue<int>q;

        q.push(0);
        vis[0] = true;

        int steps = 0;

        while(!q.empty()){
            int size = q.size();

            while(size--){
                int curr = q.front();
                q.pop();

                if(curr == n-1){
                    return steps;
                }

                int left = curr-1;
                int right = curr+1;

                if(left>=0 && !vis[left]){
                    vis[left] = true;
                    q.push(left);
                }

                if(right<n && !vis[right]){
                    vis[right] = true;
                    q.push(right);
                }

                for(auto idx: mp[arr[curr]]){
                    if(!vis[idx]){
                        vis[idx] = true;
                        q.push(idx);
                    }
                }
                mp.erase(arr[curr]);
            }
            steps++;
        }
        return -1;

    }
};