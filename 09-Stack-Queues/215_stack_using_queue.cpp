/*
    Problem: Implement Stack using Queues (LeetCode 225)
    Platform: LeetCode / Self Practice
    Link: https://leetcode.com/problems/implement-stack-using-queues/
    Difficulty: Easy
    Approach: Single Queue Rotation — push element then rotate previous N elements behind it
    Time: O(N) for push, O(1) for pop/top/empty
    Space: O(N) auxiliary space
*/
#include <iostream>
#include <queue>

using namespace std;

class MyStack {
private:
    queue<int> q;

public:
    MyStack() {}

    // Push element x onto stack (O(N) rotation)
    void push(int x) {
        int s = q.size();
        q.push(x);

        // Rotate all previous elements behind the newly added element
        for (int i = 0; i < s; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    // Removes the element on top of the stack and returns it (O(1))
    int pop() {
        if (q.empty()) {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        int val = q.front();
        q.pop();
        return val;
    }

    // Get the top element (O(1))
    int top() {
        if (q.empty()) {
            cout << "Stack is empty!" << endl;
            return -1; // FIXED: Guard against empty queue access
        }
        return q.front();
    }

    // Returns whether the stack is empty (O(1))
    bool empty() {
        return q.empty();
    }
};

int main() {
    MyStack st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Popped: " << st.pop() << endl; // Output: 30
    cout << "Top: " << st.top() << endl;       // Output: 20

    return 0;
}