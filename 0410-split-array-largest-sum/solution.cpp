class Solution {
public:
    int minpage(vector<int> &arr, int mid){
        int stu=1,pages=0;
        for(int x:arr){
            if(x+pages>mid){
                stu++;
                pages=x;
            }
            else pages+=x;
        }
        return stu;
    }
    int splitArray(vector<int>& arr, int k) {
      int low=*max_element(begin(arr),end(arr)),high=accumulate(begin(arr),end(arr),0),ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int ned=minpage(arr,mid);
            if(ned<=k){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;  
    }
};
