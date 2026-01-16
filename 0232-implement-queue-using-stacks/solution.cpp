class MyQueue {
public:
    stack<int> o, n;

    MyQueue() {}

    void push(int x) {
        o.push(x);
    }

    int pop() {
        if (n.empty()) {
            while (!o.empty()) {
                n.push(o.top());
                o.pop();
            }
        }
        int top = n.top();
        n.pop();
        return top;
    }

    int peek() {
        if (n.empty()) {
            while (!o.empty()) {
                n.push(o.top());
                o.pop();
            }
        }
        return n.top();
    }

    bool empty() {
        return o.empty() && n.empty();
    }
};


/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
