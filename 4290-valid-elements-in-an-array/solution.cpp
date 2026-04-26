class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int mini = INT_MIN, maxi = INT_MIN, n=nums.size();
        vector<bool> helper(n,false);
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(nums[i]>mini){
                helper[i] = true;
            }
            mini = max(nums[i],mini);
        }
        for(int i=n-1;i>=0;i--){
            if(nums[i]>maxi){
                helper[i] = true;
            }
            maxi = max(nums[i],maxi);
        }
        for(int i=0;i<n;i++){
            if(helper[i]){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};
