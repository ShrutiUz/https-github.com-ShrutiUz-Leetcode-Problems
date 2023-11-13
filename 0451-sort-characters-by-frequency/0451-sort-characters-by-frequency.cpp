class Solution {
public:
    string frequencySort(string s) {
        // we will create a  max heap
        // which will store the freq, char
        // treecccaaa
        // t -> 1
        // r -> 1
        // e -> 2
        // c -> 3
        // a -> 3
        // ans : aaaccceert

        // if we store this combination using a max heap
        // when we store the frequency in negative
        //  (-1, t)
        //  (-1, r)
        //  (-2, e)
        //  (-3, c)
        //  (-3, a)
        // then we can take them out one by one, changing the freq back to positive
        // treecccaaa
        // we can reverse it
        // aaaccceert
        // that is our answer

        priority_queue<pair<int, char>>pq;

        unordered_map<char, int>mp;
        for(char c : s){
            mp[c]++;
        }

        for(auto it: mp){
            pq.push({-it.second, it.first});
        }

        string ans = "";

        while(!pq.empty()){
            int freq = pq.top().first;
            char c = pq.top().second;
            pq.pop();

            for(int i=0; i<abs(freq); i++){
                ans += c;
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};