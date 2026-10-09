class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> map1;
        unordered_map<char, int> map2;
        for(char ch1: s){
            map1[ch1]++;
        }
        for(char ch2: t){
            map2[ch2]++;
        }
        for(const auto& [ch, count]: map1){
            auto it =  map2.find(ch);
            if(it==map2.end() || it->second != count){
                return false;
            }

        }
        for(const auto& [ch, count]: map2){
            auto it= map1.find(ch);
            if(it  == map1.end() || it->second != count){
                return false;
            }
        }
        return true;

    }
};