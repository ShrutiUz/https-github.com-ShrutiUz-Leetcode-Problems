class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        
        if(t == 0){
            if(sx == fx && sy == fy){
                return true;
            }
            return false;
        }
        
        if(sx == fx && sy == fy){
            if(t == 1) return false;
            return true;
        } 
        
        //diagonal element
        if(sx - sy == fx - fy || sx + sy == fx + fy){
            return abs(sx-fx)<=t;
        }
        
        long long x = abs(fx - sx);
        
        long long y = abs(fy - sy);
        
        long long minTime = max(x,y);
        
        if(t>=minTime){
            return true;
        }
        
        return false;
        
        
        
        
    }
};