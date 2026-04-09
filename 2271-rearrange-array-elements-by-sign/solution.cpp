class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size(),cnt=0,cnt1=1;
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                ans[cnt]=nums[i];
                cnt+=2;
            }
            if(nums[i]<0){
                ans[cnt1]=nums[i];
                cnt1+=2;
            }
        }
        return ans;
    }
};
