class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=INT_MIN,curr=0,n=nums.size();
        for(int i=0;i<n;i++){
            curr+=nums[i];
            sum=max(sum,curr);
            if(curr<0) curr=0;
        }
        return sum;
    }
};
