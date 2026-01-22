class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
     int n=size(nums),l=0,r=0,mxl=0,count=0;
     while(r<n){
        if(nums[r]==0 && count==k){
            while(l<=r && count==k){
                if(nums[l]==0) count--;
                l++;
            }
        }
        if(nums[r]==0 && count<k){
            count++;
        }
        
        mxl=max(mxl,r-l+1);
        r++;
     }
     return mxl;  
    }
};
