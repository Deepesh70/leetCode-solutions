class Solution {
public:
    bool halvesAreAlike(string s) {
        for(char &c: s){
            c = tolower(c);
        }
        int n= s.length();
        int count1 = 0;
        int count2 = 0;
        for(int i=0; i< n/2; i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] =='o'  || s[i] == 'u'){
                count1++;
            }
        }
        for(int i = n/2 ; i< n; i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] =='o'  || s[i] == 'u'){
                count2++;
            }
        }
        if(count1 == count2){
            return true;
        }
        else{
            return false;
        }
    }
};