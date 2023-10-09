// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long start = 0;
        long long end = n;
        long long firstBad;

        while(start <= end){
            long long mid = start + (end - start)/2;

            if(isBadVersion(mid) == 1){
                firstBad = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }

        return firstBad;
    }
};