class Solution {
public:
    int sumdiv(vector<int>& arr, int th){
        int sum=0;
        for(int x:arr){
            sum+=(x+th-1)/th;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& arr, int threshold) {
     int n=size(arr),st=1,end=*max_element(arr.begin(),arr.end()),ans;
     while(st<=end){
        int mid=st+(end-st)/2, val=sumdiv(arr,mid);
        if(val<=threshold){
            ans=mid;
            end=mid-1;
        }
        else st=mid+1;
     }
     return ans;
    }
};
