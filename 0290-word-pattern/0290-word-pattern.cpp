class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string word;
        stringstream ss(s);
        while(ss >> word){
            words.push_back(word);
        }
        if(pattern.length() != words.size()){
            return false;
        }
        unordered_map<char , string> chartoword;
        unordered_map<string, char> wordtochar;
        for(int i=0; i< pattern.length(); i++){
            char c= pattern[i];
            string w =words[i];
            if(chartoword.find(c) != chartoword.end()){
                if(chartoword[c] != w){
                    return false;
                }
            }else{
                chartoword[c]= w;
            }
            if(wordtochar.find(w) != wordtochar.end()){
                if(wordtochar[w] != c){
                    return false;
                }
            }else{
                wordtochar[w] = c;
            }
        }
        return true;
    }
};