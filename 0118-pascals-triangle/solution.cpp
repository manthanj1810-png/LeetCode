class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            vector<int> temp;
            long long v=1; 
            for(int j=0;j<=i;j++){
                temp.push_back(v);
                v=v*(i-j)/(j+1);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
