class Solution {
public:
    struct Node {
        int prefix = 0;
        int suffix = 0;
        int maxLen = 0;
        char leftChar = 0;
        char rightChar = 0;
    };

    int n;
    vector<Node> segTree;

    Node merge(const Node &L, const Node &R, int leftLen, int rightLen) {
        Node res;
        res.leftChar = L.leftChar;
        res.rightChar = R.rightChar;

        res.prefix = L.prefix;
        if (L.prefix == leftLen && L.rightChar == R.leftChar) {
            res.prefix = L.prefix + R.prefix;
        }

        res.suffix = R.suffix;
        if (R.suffix == rightLen && L.rightChar == R.leftChar) {
            res.suffix = R.suffix + L.suffix;
        }

        res.maxLen = max(L.maxLen, R.maxLen);
        if (L.rightChar == R.leftChar) {
            res.maxLen = max(res.maxLen, L.suffix + R.prefix);
        }

        return res;
    }

    void buildSegmentTree(int i, int l, int r, const string &s) {
        if (l == r) {
            segTree[i] = {1, 1, 1, s[l], s[l]};
            return;
        }
        int mid = l + (r - l) / 2;
        buildSegmentTree(2 * i + 1, l, mid, s);
        buildSegmentTree(2 * i + 2, mid + 1, r, s);
        segTree[i] = merge(segTree[2 * i + 1], segTree[2 * i + 2], mid - l + 1, r - mid);
    }

    void update(int i, int l, int r, int pos, char ch) {
        if (l == r) {
            segTree[i] = {1, 1, 1, ch, ch};
            return;
        }
        int mid = l + (r - l) / 2;
        if (pos <= mid) {
            update(2 * i + 1, l, mid, pos, ch);
        } else {
            update(2 * i + 2, mid + 1, r, pos, ch);
        }
        segTree[i] = merge(segTree[2 * i + 1], segTree[2 * i + 2], mid - l + 1, r - mid);
    }

    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        n = s.size();
        segTree.assign(4 * n, Node());
        buildSegmentTree(0, 0, n - 1, s);

        int k = queryIndices.size();
        vector<int> result(k);
        for (int i = 0; i < k; i++) {
            update(0, 0, n - 1, queryIndices[i], queryCharacters[i]);
            result[i] = segTree[0].maxLen;
        }
        return result;
    }
};