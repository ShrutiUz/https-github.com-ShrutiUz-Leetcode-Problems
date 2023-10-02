class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size();
        // int count_a = 0, count_b = 0;
        
        //using one variable: increment for alice and decrement for bob
        //return true if the variable is positive at the end
        //else return false;

        int count = 0;

        for(int i=1; i<n-1; i++){
            if(colors[i] == 'A'){
                if(colors[i-1] == 'A' && colors[i+1] == 'A'){
                    // count_a++;
                    count++;
                }
            }
            else if(colors[i] == 'B'){
                if(colors[i-1] == 'B' && colors[i+1] == 'B'){
                    // count_b++;
                    count--;
                }
            }
        }

        // return count_a>count_b;
        return count>0;
    }
};