class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n= s.length();
        unordered_map<char, int> mp;
        int left = 0;
        int max_len=0;
        for(int i = 0; i<n; i++){
            mp[s[i]]++;
            while(mp[s[i]] >2){
                mp[s[left]]--;
                left++;
            }
        max_len = max(max_len,  i - left +1);
        }
        
        return max_len;
    }
};