class Solution {
public:
    int largestVariance(string s) {
        vector<int> Count(26,0);
        for(char &ch: s){
            Count[ch - 'a'] = 1;
        }
        int result = 0;

        for(char first = 'a' ; first<= 'z'; first++){
            for(char second = 'a'; second<= 'z' ; second++){
                if(Count[first - 'a'] == 0 || Count[second -'a'] == 0){
                    continue;
                }
                int firstCount = 0;
                int secondCount = 0;
                bool pastsecond = false;
                for(char & ch : s){
                    if(ch == first){
                        firstCount++;
                
                    }
                    if(ch == second){
                        secondCount++;
                    }
                    if(secondCount > 0){
                        result = max(result, firstCount -secondCount);
                    }
                    else{
                        if(pastsecond == true){
                            result = max(result, firstCount -1);
                        }
                    }

                if(secondCount > firstCount){
                    firstCount = 0;
                    secondCount =0;
                    pastsecond = true;
                }
                }
            }
        }
        return result;
    }
};