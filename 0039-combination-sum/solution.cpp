class Solution {
public:
set<vector<int>> s;
    void helper(vector<int>& arr, int target,int i,vector<int>& ans,vector<vector<int>>& res){
        if(i==size(arr) || target<0) return;
        if(target==0){
            if(s.find(ans)==s.end()){
            res.push_back(ans);
            s.insert(ans);
            return;
            }
        }
        ans.push_back(arr[i]);
        helper(arr,target-arr[i],i+1,ans,res);
        helper(arr,target-arr[i],i,ans,res);
        ans.pop_back();
        helper(arr,target,i+1,ans,res);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> res;
        vector<int> ans;
        helper(arr,target,0,ans,res);
        return res;
    }
};
