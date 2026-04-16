class Solution {
public:
    long long helper(int mid,vector<int>& piles){
        long long i=0,ans=0;
        while(i<piles.size()){
            ans += (long long) (piles[i]+mid-1)/mid;
            i++;
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
       int l=1,r=*max_element(piles.begin(),piles.end()),ans=0;
       while(l<=r){
        int mid=l+(r-l)/2;
        if(helper(mid,piles)<=h){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
       }
       return ans;
    }
};
