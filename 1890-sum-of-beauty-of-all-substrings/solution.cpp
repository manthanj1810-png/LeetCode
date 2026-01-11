class Solution {
public:
    int beautySum(string s) {
        int n = s.size(), res = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<char, int> freq;

            for (int j = i; j < n; j++) {
                freq[s[j]]++;

                int mx = INT_MIN, mn = INT_MAX;

                for (auto &p : freq) {
                    mx = max(mx, p.second);
                    mn = min(mn, p.second);
                }

                res += (mx - mn);
            }
        }
        return res;
    }
};


