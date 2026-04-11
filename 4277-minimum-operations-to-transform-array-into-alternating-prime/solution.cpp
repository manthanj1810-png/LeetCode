class Solution {
public:
    bool isprime(int n){
        if(n<2) return false;
        for(int i=2;i*i<=n;i++){
            if(n%i==0 && i!=n) return false;
        }
        return true;
    }
    int minOperations(vector<int>& nums) {
        int n=nums.size(),cnt=0;
        for(int i=0;i<n;i++){
            if(i%2==0){
                if(!isprime(nums[i])){
                    while(!isprime(nums[i])){
                        cnt++;
                        nums[i]++;
                    }
                }
            }
            if(i%2!=0){
                if(isprime(nums[i])){
                    while(isprime(nums[i])){
                        cnt++;
                        nums[i]++;
                    }
                }
            }
        }
        return cnt;
    }
};
