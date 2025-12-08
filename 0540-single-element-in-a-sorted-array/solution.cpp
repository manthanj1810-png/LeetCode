class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
      int n=size(arr),st=1,end=n-2;
      if(n==1) return arr[0]; 
      if(arr[0]!=arr[1]) return arr[0];
      if(arr[n-1]!=arr[n-2]) return arr[n-1];
      while(st<=end){
        int mid=st+(end-st)/2;
        if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1]) return arr[mid];
        if(mid%2==0 && arr[mid]==arr[mid+1] || mid%2==1 && arr[mid]==arr[mid-1]) st=mid+1;
        else end=mid-1;
      }
      return -1;  
    }
};
