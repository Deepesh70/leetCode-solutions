class Solution {
public:

    bool check(string &s){
        int arr[26] ={0};
        for(char & ch: s){
            arr[ch -'a']++;
            if(arr[ch-'a'] > 1){
                return true;

            }
        }
            return false;
    }
    bool buddyStrings(string s, string goal) {
        int n = s.length();
        int m = goal.length();
        if(m != n){
            return false;
        }
        if( s == goal){
            if(check(s)){
                return true;
            }
            else{
                return false;
            }
        }
       
        vector<int> index;
        for(int i=0; i<n; i++){
            if(s[i] != goal[i]){
                index.push_back(i);
            }
        }
        if(index.size() !=2){
            return false;
        }
        swap(s[index[0]], s[index[1]]);
        return s == goal;
 
        return true;
    }
};