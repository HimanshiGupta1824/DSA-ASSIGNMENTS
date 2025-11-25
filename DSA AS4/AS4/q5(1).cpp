#include <iostream>
#include <queue>
using namespace std;

class StackUsingQueues {
    queue<int> q1, q2;

public:
    void push(int x) {
        q1.push(x);
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty.\n";
            return;
        }

        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        cout << "Popped: " << q1.front() << endl;
        q1.pop();

        swap(q1, q2);
    }

    int top() {
        if (q1.empty()) {
            cout << "Stack is empty.\n";
            return -1;
        }

        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        int topElem = q1.front();
        q2.push(topElem);
        q1.pop();
        swap(q1, q2);
        return topElem;
    }

    bool isEmpty() {
        return q1.empty();
    }
};

int main() {
    StackUsingQueues s;
    int choice, value;

    do {
        cout << "\n1. Push\n2. Pop\n3. Top\n4. Check if Empty\n5. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                value = s.top();
                if (value != -1) cout << "Top element: " << value << endl;
                break;
            case 4:
                cout << (s.isEmpty() ? "Stack is empty.\n" : "Stack is not empty.\n");
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
