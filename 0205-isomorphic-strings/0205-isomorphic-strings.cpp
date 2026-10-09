class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n= s.length();
        int m= t.length();
        if(m != n){
            return false;
        }

        int last_seen_s[256]={0};
        int last_seen_t[256] = {0};
        for(int i=0;i < n; i++){
            char c1= s[i];
            char c2= t[i];
            if(last_seen_s[c1] != last_seen_t[c2]){
                return false;
            }
            last_seen_s[c1] =i+1;
            last_seen_t[c2] =i+1;
            
        }
        return true;

    }
};