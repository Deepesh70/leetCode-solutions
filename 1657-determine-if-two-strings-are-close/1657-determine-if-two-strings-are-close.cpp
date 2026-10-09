class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length() != word2.length()){
            return false;
        }
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        for(char &ch : word1){
            mp1[ch]++;
        }
        for(char &ch : word2){
            mp2[ch]++;
        }
        for(const auto &[key, val]: mp1){
            if(mp2.find(key) == mp2.end()){
                return false;
            }
            
        }
        vector<int> freq1;
        vector<int> freq2;
        for(const auto &[key, val]: mp1){
            freq1.push_back(val);
        }
        for(const auto &[key, val]: mp2){
            freq2.push_back(val);
        }
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());
        if(freq1 == freq2){
            return true;
        }
        return false;

    }
};