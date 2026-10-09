#include <string>

class Solution {
public:
    int minimumPushes(std::string word) {
        int n = word.length();
        int totalPushes = 0;

        for(int i=0; i< n; i++){
            if(i < 8){
                totalPushes = totalPushes + 1;

            }
            else if (i < 16 ){
                totalPushes = totalPushes + 2;
            }
            else if( i < 24){
                totalPushes = totalPushes + 3;
            }
            else{
                totalPushes = totalPushes + 4;
            }
        }

        return totalPushes;
    }
};