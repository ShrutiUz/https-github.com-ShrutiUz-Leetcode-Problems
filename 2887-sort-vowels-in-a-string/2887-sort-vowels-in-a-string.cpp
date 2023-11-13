class Solution {
public:

    bool isVowel(char c){

        if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
           c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ){
               return true;
        }
        
        return false;
    }

    string sortVowels(string s) {
        //create a DS to store the vowels present in the given string
        vector<char>vowels;

        //store the vowels
        for(char c : s){
            if(isVowel(c)){
                vowels.push_back(c);
            }
        }

        //sort the vowles
        sort(vowels.begin(), vowels.end());
        // E e O e -> E O e e

        //reverse the sorted vector
        reverse(vowels.begin(), vowels.end());
        //E O e e -> e e O E

        string t = "";

        for(char c : s){
            if(isVowel(c)){
                t += vowels.back();
                vowels.pop_back();
            }
            else{
                t += c;
            }
        }

        return t;
    }
};

//time complexity ->
//  2 times loop -> O(N)
//  sorting the vector -> O(NlogN)
//  reverseting the vector -> O(N)
//  overall O(NlogN)