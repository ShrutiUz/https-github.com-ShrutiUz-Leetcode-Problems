class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        // cout<<n<<endl;
        vector<int> maxLeft(n);
        vector<int> maxRight(n);

        // cout<<height[0]<<endl;

        maxLeft[0] = height[0];
        // cout<<maxLeft[0]<<" "<<height[0]<<endl;
        maxRight[n-1] = height[n-1];
        // cout<<maxLeft[0]<<" "<<maxRight[n-1]<<endl;

        int result = 0;

        for(int i=1; i<n; i++){
            maxLeft[i] = max(maxLeft[i-1], height[i]);
            // cout<<maxLeft[i]<<" ";
        }

        for(int i=n-2; i>=0; i--){
            maxRight[i] = max(maxRight[i+1], height[i]);
        }

        for(int i=0; i<n; i++){
            result +=( min(maxLeft[i], maxRight[i]) - height[i]);
        }
        
        return result;
    }
};