class Solution {
public:

    int getCost(int r, int target, int k) {

        int d = abs(r - target);

        return min(d, k - d);
    }

    int minOperations(vector<int>& nums, int k) {

        vector<int> velmorqati = nums;

        int n = nums.size();

        int ans = INT_MAX;

        for(int x = 0; x < k; x++) {

            for(int y = 0; y < k; y++) {

                if(x == y) continue;

                int curr = 0;

                for(int i = 0; i < n; i++) {

                    int r = ((nums[i] % k) + k) % k;

                    if(i % 2 == 0)
                        curr += getCost(r, x, k);
                    else
                        curr += getCost(r, y, k);
                }

                ans = min(ans, curr);
            }
        }

        return ans;
    }
};
