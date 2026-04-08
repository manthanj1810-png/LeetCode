class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size(),l=-1,r=0,ans=0;
        while(r<n){
            if(!nums[r]) l=r;
            ans=max(ans,r-l);
            r++;
        }
        return ans;
    }
};
