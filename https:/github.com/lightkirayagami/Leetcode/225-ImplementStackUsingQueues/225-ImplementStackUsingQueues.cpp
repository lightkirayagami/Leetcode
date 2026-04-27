// Last updated: 27/04/2026, 21:49:43
class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {}

    void push(int x) { q1.push(x); }

    int pop() {

        if (q1.size() == 1) {
            int x=q1.front();
            q1.pop();
            return x; // edgs case if only 1 element
        }

        while (q1.size() > 1) {
            int x = q1.front(); // push all elemtn in q2 until only 1 left in q1
            q1.pop();
            q2.push(x);
        }

        int ans = q1.front();
        q1.pop(); // delete the remaning element also save it as we have to
                  // return that value

        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop(); // now push all the elemtns in q2 to q1
        }
        return ans;
    }

    int top() {

        // if (q1.size() == 1) {
        //     return q1.front(); // edgs case if only 1 element
        // }

        // while (q1.size() > 1) {
        //     int x = q1.front(); // push all elemtn in q2 until only 1 left in q1
        //     q1.pop();
        //     q2.push(x);
        // }

        // int ans = q1.front();
        // q1.pop(); // delete the remaning element also save it as we have to
        //           // return that value

        // while (!q2.empty()) {
        //     q1.push(q2.front());
        //     q2.pop(); // now push all the elemtns in q2 to q1
        // }
        // return ans;

        return q1.back();


    }

    bool empty() {
        if (q1.empty()&&q2.empty()) {
            return true;
        }
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */