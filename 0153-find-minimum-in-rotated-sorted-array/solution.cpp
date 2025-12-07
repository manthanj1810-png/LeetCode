class Solution {
public:
    int findMin(vector<int>& arr) {
    int n=size(arr),st=0,end=n-1,mina=INT_MAX;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(arr[st]<=arr[mid]){
            mina=min(arr[st],mina);
            st=mid+1;
        }
        else{
            mina=min(arr[mid],mina);
            end=mid-1;
        }
    }
    return mina;
}
};
