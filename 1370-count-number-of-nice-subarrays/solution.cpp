class Solution {
public:
    int helper(vector<int>& nums, int k){
     int n=size(nums),l=0,r=0,count=0,ans=0;
     while(r<n){
        if(nums[r]%2==1) count++;
        if(count>k){
            while(l<=r && count>k){
                if(nums[l]%2==1) count--;
                l++;
            }
        }
        ans+=r-l+1;
        r++;
     }
     return ans; 
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
     return helper(nums,k)-helper(nums,k-1);  
    }
};
