class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
      stack<int> st;
      int n=size(ast);
      for(int i=n-1;i>=0;i--){
        if(ast[i]<0){
            st.push(ast[i]);   
        }
        else{
            while(!st.empty() && st.top()<0 && -(st.top())<ast[i]){
                st.pop();
            }
            if(!st.empty()&& st.top()>0) st.push(ast[i]);
            if(!st.empty()&&-(st.top())==ast[i]) st.pop();
            else if(st.empty()) st.push(ast[i]);
        }
      }
      vector<int> ans;
      while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
      }
      return ans;  
    }
};
