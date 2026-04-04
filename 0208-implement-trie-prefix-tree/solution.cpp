struct node{
    node *links[26]={nullptr};
    bool flag=false;
    bool containskey(char c){
        return links[c-'a']!=nullptr;
    }
    void put(char c, node *xyz){
        links[c-'a']=xyz;
    }
    node* get(char c){
        return links[c-'a'];
    }
    void setend(){
        flag=true;
    }
    bool isend(){
        return flag;
    }
};
class Trie {
public:
node *root;
    Trie() {
       root=new node(); 
    }
    
    void insert(string word) {
        node *nwode=root;
        for(char c:word){
            if(!nwode->containskey(c)){
                nwode->put(c,new node());
            }
            nwode=nwode->get(c);
        }
        nwode->setend();
    }
    
    bool search(string word) {
        node *nwode=root;
        for(char c:word){
            if(!nwode->containskey(c)) return false;
            nwode=nwode->get(c);
        }
        return nwode->isend();
    }
    
    bool startsWith(string prefix) {
        node* nwode=root;
        for(char c: prefix){
            if(!nwode->containskey(c)) return false;
            nwode=nwode->get(c);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
