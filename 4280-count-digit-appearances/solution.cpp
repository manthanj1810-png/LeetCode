class Solution {
public:
    void helper(int n,unordered_map<int,int> &mp,int digit){
        while(n>0){
            int x=n%10;
            if(x==digit) mp[x]++;
            n=n/10;
        }
    }
    int countDigitOccurrences(vector<int>& nums, int digit) {
        unordered_map<int,int> mp;
        for(int y:nums){
            helper(y,mp,digit);
        }
        return mp[digit];
    }
};
