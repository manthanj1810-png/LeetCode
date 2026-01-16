class Solution {
public:
vector<vector<int>> res;
vector<int> ans;
    void help(vector<int>& nums,int i){
        if(i>=size(nums)){
            
                res.push_back(ans);
                return;
        }
        
            ans.push_back(nums[i]);
            help(nums,i+1);
            ans.pop_back();
            int in=i+1;
            while(in<size(nums) && nums[in]==nums[in-1]) in++;
            help(nums,in);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(begin(nums),end(nums));
        help(nums,0);
        return res;
    }
};
