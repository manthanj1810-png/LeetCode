class Solution {
public:
    int solve(vector<int>& nums,int l,int r){
        int n=size(nums);
        int prev2=0,prev1=nums[l];
        for(int i=l+1;i<r;i++){
            int include=nums[i]+prev2, exclude=prev1;
            int curr=max(include,exclude);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n=size(nums);
        if(n==1) return nums[0];
        int arr1=solve(nums,1,n);
        int arr2=solve(nums,0,n-1);
        return max(arr1,arr2);
    }
};
