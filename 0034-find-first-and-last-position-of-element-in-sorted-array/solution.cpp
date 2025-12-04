class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
      int n=size(arr),st=0,end=n-1,fo=-1,lo=-1;
      vector<int> ans;
      while(st<=end){
        int mid=st+(end-st)/2;
        if(arr[mid]==target){
            fo=mid;
            end=mid-1;
        }
        else if(arr[mid]>target){
            end=mid-1;
        }
        else st=mid+1;
      }
      ans.push_back(fo);
      st=0; end=n-1;
      while(st<=end){
        int mid=st+(end-st)/2;
        if(arr[mid]==target){
            lo=mid;
            st=mid+1;
        }
        else if(arr[mid]>target){
            end=mid-1;
        }
        else st=mid+1;
      }
      ans.push_back(lo);
      return ans;
    }
};
