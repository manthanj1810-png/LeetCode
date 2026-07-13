class NumArray {
public:
int n;
vector<int> a;
    NumArray(vector<int>& nums) {
        n=nums.size();
        a=nums;
    }
    vector<int> prefixSum(vector<int> &nums){
        long long sum=0;
        vector<int> hash(n);
        for(int i=0;i<n;i++){
            sum+=nums[i];
            hash[i]=sum;
        }
        return hash;
    }
    int sumRange(int left, int right) {
        vector<int> hash=prefixSum(a);
        if(left==0) return hash[right];
        return hash[right]-hash[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
