class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n= nums.size();
        sort(begin(nums), end(nums));
        int closestsum = nums[0] + nums[1] + nums[2];
        for(int k= 0; k < n-2; k++){
            int i = k+1;
            int j = n-1;
            while(i< j){
                int sum  = nums[i] + nums[j] + nums[k];
                if(abs(target-sum) < abs(target- closestsum)){
                    closestsum = sum;
                }
                if(sum < target){
                    i++;
                }
                else{
                    j--;
                }
            }

        }
        return closestsum;
    }
};