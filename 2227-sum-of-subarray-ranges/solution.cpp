class Solution {
public:
vector<int> nse(vector<int>& nums){
    int n=nums.size();
    vector<int> ans(n,n);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && nums[st.top()]>=nums[i]) st.pop();
        if(!st.empty()) ans[i]=st.top();
        st.push(i);
    }
    return ans;
}
vector<int> nge(vector<int>& nums){
    int n=nums.size();
    vector<int> ans(n,n);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && nums[st.top()]<=nums[i]) st.pop();
        if(!st.empty()) ans[i]=st.top();
        st.push(i);
    }
    return ans;
}
vector<int> psee(vector<int>& nums){
    int n=nums.size();
    vector<int> ans(n,-1);
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && nums[st.top()]>nums[i]) st.pop();
        if(!st.empty()) ans[i]=st.top();
        st.push(i);
    }
    return ans;
}
vector<int> pgee(vector<int>& nums){
    int n=nums.size();
    vector<int> ans(n,-1);
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && nums[st.top()]<nums[i]) st.pop();
        if(!st.empty()) ans[i]=st.top();
        st.push(i);
    }
    return ans;
}
    long long subArrayRanges(vector<int>& nums) {
      int n=nums.size();
      long long sum=0;
      vector<int> NSE=nse(nums),NGE=nge(nums),PGE=pgee(nums),PSE=psee(nums);
      for(int i=0;i<n;i++){
        long long mini= (i-PSE[i])*(NSE[i]-i);
        long long maxi= (i-PGE[i])*(NGE[i]-i);
        sum+= (maxi-mini)*nums[i];
      }
      return sum;
    }
};
