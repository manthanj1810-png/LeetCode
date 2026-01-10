class Solution {
public:
    string frequencySort(string s) {
      string res="";
      unordered_map<char,int> arr;
      for(auto i:s){
        arr[i]++;
      }
       vector<pair<int,char>>v;
       for(auto &p:arr){
        v.push_back({p.second,p.first});
       }
       sort(begin(v),end(v),greater<>());
      for(auto &p:v){
        res.append(p.first,p.second);
      }
      return res;
    }
};
