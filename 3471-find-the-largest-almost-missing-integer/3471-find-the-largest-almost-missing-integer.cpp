class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(const auto& i: nums){
            mp[i]++;
        }
        
        if(k == 1){
            int max_val=-1;
            for(auto &[value, count]: mp){
                if(count ==1){
                    max_val = max(max_val, value);
                }
            }
            return max_val;
        }


        if(k == nums.size()){
            int max_val =  -1;
            for(int num:nums){
                max_val = max(num, max_val);
            }
            return max_val;
        }

        int n = nums.size();
        if(nums[0] == nums[n-1]){
            return -1;
        }
        int max_val = -1;
        if(mp[nums[0]] == 1){
            max_val = max(max_val, nums[0]);
        } 
        if(mp[nums[n-1]] == 1){
            max_val = max(max_val,nums[n-1]);
        }
        return max_val;

    }
};