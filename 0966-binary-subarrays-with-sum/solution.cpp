class Solution {
public:
    int helper(vector<int>& nums, int goal){
        int n=size(nums),l=0,r=0,count=0,sum=0;
        while(r<n){
            sum+=nums[r];
            if(sum>goal){
                while(l<=r && sum>goal){
                    sum-=nums[l];
                    l++;
                }
            }
            count+=r-l+1;
            r++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
      return helper(nums,goal)-helper(nums,goal-1);
    } 
};
