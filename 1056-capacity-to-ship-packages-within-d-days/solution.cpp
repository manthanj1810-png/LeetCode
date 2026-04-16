class Solution {
public:
    long long helper(int mid,vector<int>& weights){
       long long days=1,sum=0;
       for(int i=0;i<weights.size();i++){
        if(sum+weights[i]>mid){
            days++;
            sum=weights[i];
        }else sum+=weights[i];
       }
       return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
       int l=*max_element(weights.begin(),weights.end()),r=accumulate(weights.begin(),weights.end(),0),ans=r;
       while(l<=r){
        int mid=l+(r-l)/2;
        if(helper(mid,weights)<=days){
            ans=mid;
            r=mid-1;
        }else l=mid+1;
       }
       return ans;
    }
};
