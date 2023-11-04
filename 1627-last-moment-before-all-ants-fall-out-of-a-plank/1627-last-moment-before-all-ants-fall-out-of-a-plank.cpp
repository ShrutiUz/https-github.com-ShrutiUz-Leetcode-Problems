class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // if(left.size() == 0){
        //     return right.size()-1;
        // }
        
        // if(right.size() == 0){
        //     return left.size()-1;
        // }

        int leftMax = INT_MIN;
        int rightMin = INT_MAX;

        int leftCount = left.size();
        int rightCount = right.size();

        //we need to find the maximum element from the left array
        for(int i=0; i<leftCount; i++){
            leftMax = max(leftMax, left[i]);
        }

        //we need to find the minimum element from the right array
        for(int i=0; i<rightCount; i++){
            rightMin = min(rightMin, right[i]);
        }

        rightMin = n - rightMin;

        return max(rightMin, leftMax);
    }
};