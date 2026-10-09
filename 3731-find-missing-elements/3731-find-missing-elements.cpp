class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        if(nums.empty()) return {};

        sort(nums.begin(), nums.end());

        vector<int> arr;

        for(int i = 0; i< nums.size() -1; i++){
            int curr = nums[i] + 1;
            while(curr < nums[i+ 1]){
                arr.push_back(curr);
                curr++;
            }
            
        }
        return arr;
    }
};