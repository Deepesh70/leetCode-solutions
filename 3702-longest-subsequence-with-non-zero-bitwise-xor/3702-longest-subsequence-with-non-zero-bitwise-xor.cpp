class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n= nums.size();

        int result = 0;
        bool allzero = true;
        for(int &i: nums){
            result = (result ^ i);
            if(i!=0){
                allzero= false;
            }
        }
        if(allzero){
            return 0;
        }
        if(result == 0){
            return n-1;

        }
        else
        {
            return n;
        }
    }
};