class Solution {
public:
 vector<vector<int>> res;
 vector<int> ans;
 vector<int> nums={1,2,3,4,5,6,7,8,9};
    void help(int k,int n,int i){
        if(k==0 && n==0){
            res.push_back(ans);
            return;
        }
        if(n<0 || k<0 || i>=size(nums)) return;
        ans.push_back(nums[i]);
        help(k-1,n-nums[i],i+1);
        ans.pop_back();
        help(k,n,i+1);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
       help(k,n,0);
       return res;
    }
};
