class Solution {
public:

    bool check(vector<int>&arr){
        //find the min and max element

        int siz = arr.size();
        int minn = INT_MAX;
        int maxx = INT_MIN;
        unordered_set<int>st;

        for(int num : arr){
            minn = min(minn, num);
            maxx = max(maxx, num);
            st.insert(num);
        }

        if((maxx-minn)%(siz-1) != 0){
            return false;
        }

        int diff = (maxx - minn)/(siz-1);

        int curr = minn + diff;

        while(curr<maxx){
            if(st.find(curr) == st.end()){
                return false;
            }
            curr += diff;
        }

        return true;

    }

    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        //leaving this for now
        //do it by the evening shruti
        //use the AP formula
        //and the approach to divide the array in subarrays from the brute force approach

        vector<bool>ans;

        int m = l.size();

        for(int i=0; i<m; i++){

            vector<int>arr(nums.begin()+l[i], nums.begin()+r[i]+1);
            ans.push_back(check(arr));
        }

        return ans;
    }
};