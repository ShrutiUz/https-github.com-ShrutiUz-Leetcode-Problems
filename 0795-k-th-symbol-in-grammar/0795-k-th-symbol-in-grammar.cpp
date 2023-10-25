class Solution {
public:
    int kthGrammar(int n, int k) 
    {
        int l=1, r=pow(2,n-1);
        int ans=0;
        while (l<r) 
        {
            int mid=(l+r)/2;
            if (k<=mid) r=mid;
            else 
            {
                ans=1-ans;
                l=mid+1;
            }
        }
        return ans;
    }
};