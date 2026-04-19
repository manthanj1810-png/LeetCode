class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
       int n=nums.size(),maxi=INT_MIN,r=0;
        while(r<n){
            if(maxi<nums[r]){
                maxi=nums[r];
            }
            int l=r,mini=INT_MAX;
            while(l<n){
              if(mini>nums[l]){
                  mini=nums[l];
              }
                l++;
            }
            if(maxi-mini<=k) return r;
            r++;
        }
        return -1;
    }
};
