class Solution {


public:
    static bool compare(const pair<char, int>& a, const pair<char, int> b){
        return a.second > b.second;
    }
    int minimumPushes(string word) {
        unordered_map<char, int> freq;
        for(char c: word){
            freq[c]++;
        }

        vector<pair<char, int>> freqvec(freq.begin(), freq.end());
        sort(freqvec.begin(), freqvec.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second > b.second;
            });
        
        int totalPush = 0;

        for(int i =0; i< freqvec.size(); i++){
            int count = freqvec[i].second;
            if( i< 8){
                totalPush = totalPush + count*1;
            }
            else if(i < 16){
                totalPush = totalPush + count *2;
            } else if( i < 24){
                totalPush = totalPush + count* 3;
            }else{
                totalPush = totalPush + count* 4;
            }
            
        }
        return totalPush;
    }
};