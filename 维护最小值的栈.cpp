#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct ExtendStack {
    stack<int> stk;
    stack<int> stkmin;
    void push(int x) {
        stk.push(x);
        if (stkmin.empty() || x <= stkmin.top())
            stkmin.push(x);
    }
    int top() {
        return stk.top();
    }
    int pop() {
        int rst = stk.top();
        stk.pop();
        if (rst == stkmin.top())
            stkmin.pop();
        return rst;
    }
    int min() {
        return stkmin.top();
    }
    size_t size() {
        return stk.size();
    }
    bool empty() {
        return stk.empty();
    }
};

int main() {
    ExtendStack s;
    string in;
    while (cin >> in) {
        if (in == "push") {
            int x;
            cin >> x;
            s.push(x);
            cout << x << " is pushed." << endl;
        }
        else if (in == "top") {
            if (s.empty()) {
                cout << "Stack is empty." << endl;
            }
            else {
                cout << s.top() << endl;
            }
        }
        else if (in == "pop") {
            if (s.empty()) {
                cout << "Stack is empty." << endl;
            }
            else {
                cout << s.pop() << endl;
            }
        }
        else if (in == "min") {
            if (s.empty()) {
                cout << "Stack is empty." << endl;
            }
            else {
                cout << s.min() << endl;
            }
        }
        else {
            cout << "Illegal input." << endl;
        }
    }
    return 0;
}
