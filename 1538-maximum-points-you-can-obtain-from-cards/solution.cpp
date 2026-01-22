class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
      int n=size(nums),l=0,r=n-k-1,mxsum=0,tlsum=0,sum=0;
      for(int x:nums) tlsum+=x;
      for(int i=l;i<=r;i++) sum+=nums[i];
      while(r<n){
        mxsum=max(mxsum,tlsum-sum);
        r++;
        if(r<n) sum+=nums[r];
        else break;
        sum-=nums[l];
        l++;
      }
      return mxsum; 
    }
};
