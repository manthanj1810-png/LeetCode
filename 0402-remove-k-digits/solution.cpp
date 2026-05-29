class Solution {
public:
    string removeKdigits(string num, int k) {
      int n=num.size();
      if(k==n) return "0";
      stack<char> st;
      string res="";
      for(int i=0;i<n;i++){
        while(!st.empty() && k>0 && st.top()>num[i]){
            st.pop();
            k--;
        }
        st.push(num[i]);
      }
      while(!st.empty() && k>0) {
            st.pop();
            k--;
        }
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        while(!res.empty() && res.back()=='0') res.pop_back();
        if(res.empty()) return "0";
        reverse(res.begin(),res.end());
        return res;
    }
};
