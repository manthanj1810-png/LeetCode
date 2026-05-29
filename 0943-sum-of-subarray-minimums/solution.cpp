class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size(), mod=1e9+7;
        long long sum=0;
        vector<int> nse(n,n),psee(n,-1);
        stack<pair<int,int>> st1,st2;
        for(int i=n-1;i>=0;i--){
            while(!st1.empty()&& st1.top().second>=arr[i]) st1.pop();
            if(!st1.empty()) nse[i]=st1.top().first;
            st1.push({i,arr[i]});
        }
        for(int i=0;i<n;i++){
            while(!st2.empty()&& st2.top().second>arr[i]) st2.pop();
            if(!st2.empty()) psee[i]=st2.top().first;
            st2.push({i,arr[i]});
        }
        for(int i=0;i<n;i++){
            int left= i-psee[i], right=nse[i]-i;
            long long freq=(left*right*1LL);
            sum= (sum+(freq*arr[i]*1LL%mod))%mod; 
        }
        return sum;
    }
};
