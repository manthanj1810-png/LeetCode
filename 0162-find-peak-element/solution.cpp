class Solution {
public:
    int findPeakElement(vector<int>& arr) {
      int n=size(arr),st=0,end=n-1;
      while(st<end){
        int mid=st+(end-st)/2;
        if(arr[mid]>arr[mid+1]){
            end=mid;
        }
        else st=mid+1;
      }
      return st;
    }
};
