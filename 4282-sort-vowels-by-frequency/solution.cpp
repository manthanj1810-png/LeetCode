class Solution {
public:
    string sortVowels(string &s) {
      priority_queue<tuple<int,int,char>> pq;
        unordered_map<char,int> freq,posi;
        int n=s.size(),cnt=0;
        for(int i=0;i<n;i++){
            char c=s[i];
            if(c=='a'|| c=='e'|| c=='i'|| c=='o'|| c=='u'){
                freq[c]++;
                if(posi.find(c)==posi.end()) posi[c]=i;
            }
        }
        for(auto &it:freq){
            char c=it.first;
            pq.push({it.second,-posi[c],c});
        }
        for(int i=0;i<n;i++){
            char c=s[i];
           if(c=='a'|| c=='e'|| c=='i'|| c=='o'|| c=='u'){
               auto [x,t,c]=pq.top();
               s[i]=c;
               cnt++;
               if(x==cnt){
                   pq.pop();
                   cnt=0;
               } 
           } 
        }
        return s;
    }
};
