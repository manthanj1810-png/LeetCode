class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size(),cnt=0,cnt1=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                cnt++;
            }
            if(nums[i]==1) cnt1++;
        }
        int i=0;
        while(i<n){
            if(cnt!=0){
                nums[i]=0;
                cnt--;
                i++;
            }
            if(cnt==0 && cnt1!=0){
                nums[i]=1;
                cnt1--;
                i++;
            }
            if(cnt1==0 && cnt==0 && i<n){
                nums[i]=2;
                i++;
            }
        }
    }
};
