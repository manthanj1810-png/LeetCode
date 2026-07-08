class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;

        auto expand = [&](int l, int r) {
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                ans++;
                l--;
                r++;
            }
        };

        for (int i = 0; i < s.size(); i++) {
            expand(i, i);       // odd-length palindromes
            expand(i, i + 1);   // even-length palindromes
        }

        return ans;
    }
};
