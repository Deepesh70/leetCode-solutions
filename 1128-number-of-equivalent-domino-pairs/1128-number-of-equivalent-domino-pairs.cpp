class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> counts;

        for(const auto& d: dominoes){
            int smaller = min(d[0], d[1]);
            int larger = max(d[0],d[1]);

            int key = smaller*10 + larger;
            counts[key]++;
        }
        int total_pairs = 0;
        for(const auto& pair:counts){
            int k = pair.second;
            if(k>1){
                total_pairs= total_pairs+ (k*(k-1) / 2);
            }
        }
        return total_pairs;
    }
};