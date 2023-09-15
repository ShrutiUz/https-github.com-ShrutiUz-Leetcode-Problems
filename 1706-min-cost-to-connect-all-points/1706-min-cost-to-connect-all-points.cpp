class DisjointSet{
    public:
        vector<int> parent,size;
        DisjointSet(int n){
            parent.resize(n+1);
            for(int i=0;i<=n;i++)
                parent[i]=i;
            size.resize(n+1);
        }
        int findUPar(int node){
            if(parent[node]==node)
                return node;
            return parent[node]=findUPar(parent[node]);
        }
        void unionBySize(int node1,int node2){
            int ulp_u=findUPar(node1);
            int ulp_v=findUPar(node2);
            if(ulp_u==ulp_v)
                return;
            if(size[ulp_u]<size[ulp_v]){
                parent[ulp_u]=ulp_v;
                size[ulp_v]+=size[ulp_u];
            }else{
                parent[ulp_v]=ulp_u;
                size[ulp_u]+=size[ulp_v];
            }
        }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<pair<int,pair<int,int>>> v;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                v.push_back({abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]),{i,j}});
            }
        }
        DisjointSet ds(n);
        sort(v.begin(),v.end());
        int ans=0;
        for(auto it: v){
            int adjWt=it.first;
            int u=it.second.first;
            int v=it.second.second;
            if(ds.findUPar(u)!=ds.findUPar(v)){
                ans+=adjWt;
                ds.unionBySize(u,v);
            }
        }
        return ans;
    }
};