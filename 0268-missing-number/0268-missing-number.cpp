class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int actualsum = n*(n+1)/2;
        int sum = 0;
        for(const auto& i: nums){
            sum = sum+ i;
        }
        return actualsum - sum;
    }
};