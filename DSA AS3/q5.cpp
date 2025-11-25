#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

int evaluatePostfix(string expr) {
    stack<int> s;
    for(char c : expr) {
        if(isdigit(c)) s.push(c - '0');
        else {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            if(c == '+') s.push(a + b);
            else if(c == '-') s.push(a - b);
            else if(c == '*') s.push(a * b);
            else if(c == '/') s.push(a / b);
            else if(c == '^') {
                int res = 1;
                for(int i = 0; i < b; i++) res *= a;
                s.push(res);
            }
        }
    }
    return s.top();
}

int main() {
    string expr;
    cin >> expr;
    cout << evaluatePostfix(expr) << endl;
    return 0;
}
