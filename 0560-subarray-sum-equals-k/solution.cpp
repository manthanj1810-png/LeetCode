class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size(),sum=0,ans=0;
        unordered_map<int,int> s;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum==k) ans++;
            int rem=sum-k;
            if(s.find(rem)!=s.end()){
                ans+=s[rem];
            }
            s[sum]++;
        }
        return ans;
    }
};
