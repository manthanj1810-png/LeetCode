class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),end(intervals));
      vector<vector<int>> ans;
      ans.push_back(intervals[0]);
      for(int i=0;i<size(intervals);i++){
        auto &last=ans.back();
        if(intervals[i][0]<=last[1]){
            last[1]=max(last[1],intervals[i][1]);
        }
        else ans.push_back(intervals[i]);
      }
      return ans;
    }
};
