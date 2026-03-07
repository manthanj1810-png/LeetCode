class Solution {
public:
set<vector<int>> res;
    void solve(int i,vector<int>& nums,vector<int> &ans){
        if(i!=0){
            if(res.find(ans)==res.end()) res.insert(ans);
        }
        if(i==nums.size()) return;
        solve(i+1,nums,ans);
        ans.push_back(nums[i]);
        solve(i+1,nums,ans);
        ans.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        solve(0,nums,ans);
        vector<vector<int>> st(res.begin(),res.end());
        return  st;
    }
};
