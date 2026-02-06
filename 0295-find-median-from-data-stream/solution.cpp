class MedianFinder {
public:
priority_queue<int> maxh;
priority_queue<int,vector<int>,greater<int>> minh;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxh.empty()|| maxh.top()>=num){
            maxh.push(num);
        }
        else minh.push(num);
        if(abs((int) size(maxh) -(int) size(minh))>1){
            if(size(maxh)>size(minh)){
                minh.push(maxh.top());
                maxh.pop();
            }
            else{
                maxh.push(minh.top());
                minh.pop();
            }
        }
    }
    
    double findMedian() {
        int n=size(maxh),m=size(minh);
        if(n==m){
            return (maxh.top()+minh.top())/ 2.0;
        }
        else return (n>m) ? maxh.top(): minh.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
