class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if(x + y < target) return false;
        int a = gcd(x,y);
        if(target % a == 0){
            return true;
        }
        return false;
    }
};