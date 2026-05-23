class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n=nums.size(),count=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                count++;
            }
        }
        int ans=count;
        for(int i=n-1;i>=n-count;i--){
            if(nums[i]==0) ans--;
        }
        return ans;
    }
};
