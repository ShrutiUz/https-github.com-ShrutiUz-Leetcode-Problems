class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {

        int n = nums.size();
        int m = l.size();
        vector<bool>ans;

        for(int i=0; i<m; i++){

            int low = l[i];
            int high = r[i];
            // cout<<"low is "<<low<<" and high is "<<high<<endl;

            int siz = high-low+1;
            // cout<<"the size of the range is "<<siz<<endl;
            // 'siz' is the number of elements that comes in this range

            vector<int>range;

            for(int j=low; j<=high; j++){
                range.push_back(nums[j]);
                // cout<<"Pushing the element "<<nums[j]<<" in the temp vector"<<endl;
            }

            sort(range.begin(), range.end());
            
            // cout<<"after sorting ->"<<endl;
            // for(int it = 0; it<siz; it++){
            //     cout<<range[it]<<" ";
            // }
            // cout<<endl;
            int it;
            for( it = 2; it<range.size(); it++){
                if(range[it] - range[it-1] != range[1] - range[0]){
                    break;
                }
            }
            ans.push_back( it == range.size());
            
        }
        return ans;
    }
};