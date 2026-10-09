class Solution {
public:
    int n;
    vector<string> result;

    bool isValid(const string& str) {
        
        if (str.length() > 1 && str[0] == '0') return false;
        
        int val = stoi(str);
        return val >= 0 && val <= 255;
    }

    void solve(const string& s, int idx, int parts, string curr) {
        if (parts > 4) return;

        if (idx == n && parts == 4) {
            curr.pop_back(); // Remove trailing dot
            result.push_back(curr);
            return;
        }

        for (int len = 1; len <= 3; ++len) {
            if (idx + len > n) break;

            string segment = s.substr(idx, len);
            if (isValid(segment)) {
                solve(s, idx + len, parts + 1, curr + segment + ".");
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        n = s.length();
        if (n < 4 || n > 12) return {};

        solve(s, 0, 0, "");
        return result;
    }
};