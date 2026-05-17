class Solution {
public:
    int countKthRoots(int l, int r, int k) {
       long long st = ceil(pow(l, 1.0 / k) - 1e-12);
        long long end = floor(pow(r, 1.0 / k) + 1e-12);
        return max(0LL,end-st+1);
    }
};
