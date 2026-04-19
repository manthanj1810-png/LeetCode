class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size(),maxi=INT_MIN,mini=INT_MAX;
        vector<int> arr1(n,INT_MIN),arr2(n,INT_MAX);
        for(int i=0;i<n;i++){
            if(maxi<nums[i]){
                maxi=nums[i];
            }
            arr1[i]=maxi;
        }
        for(int i=n-1;i>=0;i--){
            if(mini>nums[i]) mini=nums[i];
            arr2[i]=mini;
        }
        for(int i=0;i<n;i++){
            if(arr1[i]-arr2[i]<=k)return i;
        }
        return -1;
    }
};
