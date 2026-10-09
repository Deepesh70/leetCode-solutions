class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> map1;
        for(char & ch: s){
            map1[ch]++;
        }

        int size = 0;
        bool has_odd= false;
        for(auto& pair: map1){
            int freq= pair.second;
            if(freq%2 !=0){
                has_odd = true;
                size = size+ freq -1;
            }else{
                size = size+ freq;
            }
        }
        if(has_odd){
            size = size+1;
        }
               
    return size;
    }
};