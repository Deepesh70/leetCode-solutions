class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagram_group;
        for(const string    & s: strs){
            string key = s;
            sort(key.begin(), key.end());
            anagram_group[key].push_back(s);
        }
        vector<vector<string>> result;
        for(auto & pair: anagram_group){
            result.push_back(move(pair.second));
        }
        return result;
    }
};