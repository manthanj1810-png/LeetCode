class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
     unordered_map<int,int> mp;
     for(auto x: tasks) mp[x]++;
     priority_queue<int> pq;
     for(auto &it:mp) pq.push(it.second);
     int time=0;
     while(!pq.empty()){
        vector<int> temp;
        for(int i=0;i<=n;i++){
            if(!pq.empty()){
                int x=pq.top();
                pq.pop();
                x--;
                if(x>0) temp.push_back(x);
                time++;
            }else{
                if(temp.empty()) break;
                time++;
            }
           
        }
      for(auto i:temp) pq.push(i);  
     }
     return time;   
    }
};
