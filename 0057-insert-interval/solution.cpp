class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newinterval) {
        int n=size(intervals);
        intervals.push_back(newinterval);
        sort(begin(intervals),end(intervals));
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i=1;i<size(intervals);i++){
            auto &last=ans.back();
            if(intervals[i][0]<=last[1]){
                last[1]=max(last[1],intervals[i][1]);
            }
            else ans.push_back(intervals[i]);
        }
        return ans;
    }
};
