class Solution {
public:
    int strStr(string a, string b) {
        int ans=a.find(b);
        return ans==string::npos? -1: ans;
    }
};
