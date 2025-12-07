class Solution {
public:
    int search(vector<int>& arr, int x) {
      int n=size(arr),st=0,end=n-1;
      while(st<=end){
        int mid=st+(end-st)/2;
        if(arr[mid]==x){
            return mid;
        }
        if(arr[st]<=arr[mid]){
            if(arr[st]<=x && arr[mid]>x){
                end=mid-1;
                }    
            else st=mid+1;
        }
        else{
            if(arr[mid]<x && arr[end]>=x){
                st=mid+1;
            }    
                else end=mid-1;
        }
      }
      return -1;
    }
};
