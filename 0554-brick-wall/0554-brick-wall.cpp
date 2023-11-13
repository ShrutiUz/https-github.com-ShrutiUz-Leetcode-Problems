class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {

        //create an unordered map which will store the frequency of each edge position
        unordered_map<int,int>mp;

        int max_freq = 0;

        for(int row = 0; row < wall.size(); row++){
            int edgePos = 0;

            for(int i=0; i<wall[row].size()-1; i++){
                int currEle = wall[row][i];
                edgePos += currEle;
                mp[edgePos]++;
                max_freq = max(max_freq, mp[edgePos]);
            }
        }

        return wall.size()-max_freq;

    }
};