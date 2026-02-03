class Solution {
public:
    int totalFruit(vector<int>& nums) {
        unordered_map<int,int> mp;
        int l = 0, ans = 0;

        for(int r = 0; r < nums.size(); r++){
            mp[nums[r]]++;

            // shrink window if more than 2 fruit types
            while(mp.size() > 2){
                mp[nums[l]]--;
                if(mp[nums[l]] == 0)
                    mp.erase(nums[l]);
                l++;
            }

            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};

