class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        //n by n
        vector<int>source = {0,0};
        vector<int>destination = {n-1, n-1};
        if(n==1 && grid[0][0] == 0) return 1;
        if(grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;

        vector<vector<int>>dist(n, vector<int>(n, 1e9));
        dist[0][0] = 0;

        queue<pair<int, pair<int,int>>>q;
        q.push({0, {0,0}});

        while(!q.empty()){
            int dis = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();

            for(int i=-1; i<=1; i++){
                for(int j=-1; j<=1; j++){
                    int nrow = r + i;
                    int ncol = c + j;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol] == 0 && 
                    dis + 1 <dist[nrow][ncol]){
                        dist[nrow][ncol] = 1 + dis;
                        if(nrow == destination[0] && ncol == destination[1]){
                            return 1 + dist[nrow][ncol];
                        }
                        q.push({dist[nrow][ncol], {nrow, ncol}});
                    }
                }
            }
        }
        return -1;
    }
};