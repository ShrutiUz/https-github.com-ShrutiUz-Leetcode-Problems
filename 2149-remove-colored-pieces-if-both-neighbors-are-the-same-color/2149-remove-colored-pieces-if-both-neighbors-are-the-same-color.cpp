class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size();
        int count_a = 0, count_b = 0;

        for(int i=1; i<n-1; i++){
            if(colors[i] == 'A'){
                if(colors[i-1] == 'A' && colors[i+1] == 'A'){
                    count_a++;
                }
            }
            else if(colors[i] == 'B'){
                if(colors[i-1] == 'B' && colors[i+1] == 'B'){
                    count_b++;
                }
            }
        }

        return count_a>count_b;
    }
};