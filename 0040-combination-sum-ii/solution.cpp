class Solution {
public:
vector<int> ans;
vector <vector<int>> res;
    void helper(vector<int>& arr,int i,int target){
        if(target==0){
            res.push_back(ans);
            return;
            }
        for(int j=i;j<size(arr);j++){
            if(j>i && arr[j]==arr[j-1]) continue;
            if(arr[j]>target) break;
            ans.push_back(arr[j]);
            helper(arr,j+1,target-arr[j]);
            ans.pop_back();
        }
        }
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        sort(begin(arr),end(arr));
        helper(arr,0,target);
        return res;
        }
};
