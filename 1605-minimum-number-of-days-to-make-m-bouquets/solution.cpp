class Solution {
public:
    int contD(vector<int>& bloomDay, int mid,int k){
        int ans=0,curr=0;
        for(int x:bloomDay){
            if(x<=mid) curr++;
            else{
                ans+=curr/k;
                curr=0;
            }
        }
        ans+=curr/k;
        return ans;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
       int st=1,end=*max_element(bloomDay.begin(),bloomDay.end()),resu=-1;
       while(st<=end){
        int mid=st+(end-st)/2,val=contD(bloomDay,mid,k);
        if(val>=m){
            resu=mid;
            end=mid-1;
            }
        else st=mid+1;
       }
       return resu;
    }
};
