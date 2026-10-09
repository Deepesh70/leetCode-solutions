class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        int odd_count = 0;
        int odd_index = -1;
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 != 0) {
                odd_count++;
                odd_index = i;
            }
        }
        if (odd_count > 1) {
            return "";
        }
        string half = "";
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                half.append(freq[i] / 2, (char)(i + 'a'));
            }
        }
        string result = half;

        if (odd_count == 1) {
            result.push_back((char)(odd_index + 'a'));
        }
        string rev_half = half;
        reverse(rev_half.begin(), rev_half.end());
        result = result + rev_half;
        return result;
    }
};