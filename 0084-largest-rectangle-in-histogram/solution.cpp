class Solution {
public:
    vector<int> nse(vector<int>& heights){
        int n=size(heights);
        vector<int> ans(n);
        stack<int> s;
        for(int i=n-1;i>=0;i--){
            while(!s.empty()&& heights[s.top()]>=heights[i]) s.pop();
            ans[i]=s.empty() ? n:s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int> pse(vector<int>& heights){
        int n=size(heights);
        vector<int> ans(n);
        stack<int> s;
        for(int i=0;i<n;i++){
            while(!s.empty()&& heights[s.top()]>=heights[i]) s.pop();
            ans[i]=s.empty() ? -1:s.top();
            s.push(i);
        }
        return ans;  
    }
    int largestRectangleArea(vector<int>& heights) {
       int maxarea=0,area,n=size(heights);
       vector<int> r=nse(heights),l=pse(heights);
       for(int i=0;i<n;i++){
        area=(r[i]-l[i]-1)*heights[i];
        maxarea=max(maxarea,area);
       }
       return maxarea;
    }
};
