// Last updated: 27/04/2026, 21:49:37
class MyQueue {
public:
    stack<int> in;
    stack<int> out;
    int peekele = -1;
    MyQueue() {}

    void push(int x) {
        if (in.empty()) {
            in.push(x);
            peekele = x;
        }
        else
        {
        in.push(x);
        }
    }

    int pop() {
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
        int ele = out.top();
        out.pop();
        return ele;
    }

    int peek() {
        if (out.empty()) {
            return peekele;
        }
        return out.top();
    }

    bool empty() {
        if (in.empty() && out.empty()) {
            return true;
        }
        return false;
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