class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_map<char, int> mp;
        for(char &c: sentence){
            mp[c]++;
            
        }
        if(mp.size() >= 26){
            return true;
        }
        else 
        return false;
        
    }
};