class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>vec;
        int n1 = nums1.size();
        int n2 = nums2.size();

        for(int i=0; i<n1; i++){
            vec.push_back(nums1[i]);
        }

        for(int i=0; i<n2; i++){
            vec.push_back(nums2[i]);
        }

        

        sort(vec.begin(), vec.end());

        for(int i =0; i<vec.size(); i++){
            cout<<vec[i]<<" ";
        }
        cout<<endl;

        int m = vec.size();
        double median;

        if(m%2== 0){
            //even size
            int idx = m/2 - 1;
            cout<<idx;
             median = double(vec[idx] + vec[idx+1])/2;
        }
        else{
            int idx = (m+1)/2 - 1;
            cout<<idx;
            median = vec[idx];
        }

        return median;
    }
};