class Solution {
public:
    int maxarea(vector<int> heights){
        int maxi=0,n=heights.size();
        stack<int> st;
        heights.push_back(0);
        for(int i=0;i<=n;i++){
            while(!st.empty() && heights[i]<heights[st.top()]){
                int height=heights[st.top()];
                st.pop();
                int width= st.empty()? i:i-st.top()-1;
                maxi=max(maxi,height*width);
            }
            st.push(i);
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix[0].size();
        vector<int> heights(m,0);
        int ans=0;
        for(auto &row:matrix){
            for(int i=0;i<m;i++){
                if(row[i]=='1') heights[i]++;
                else heights[i]=0; 
            }
            ans=max(ans,maxarea(heights));
        }
        return ans;
    }
};
