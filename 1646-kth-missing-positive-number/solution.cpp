class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
     int n=size(arr),count=0;
     unordered_map<int,int> hash;
     for(int x:arr){
        hash[x]++;
     }
     for(int i=1;i<=2000;i++){
        if(!hash[i]) count++;
        if(count==k){
            return i;
        }
     }
     return -1;
    }
};
