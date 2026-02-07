class Solution {
public:
    bool canJump(vector<int>& arr) {
        int n = arr.size();
        int farthest = 0;

        for (int i = 0; i < n; i++) {
            if (i > farthest) return false;
            farthest = max(farthest, i + arr[i]);
        }

        return true;
    }
};

