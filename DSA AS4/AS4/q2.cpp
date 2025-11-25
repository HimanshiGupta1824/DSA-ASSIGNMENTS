#include <iostream>
using namespace std;

#define MAX 5  
class CircularQueue {
    int arr[MAX];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return ((rear + 1) % MAX == front);
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot insert " << value << endl;
            return;
        }

        if (isEmpty()) {
            front = 0;
        }

        rear = (rear + 1) % MAX;
        arr[rear] = value;
        cout << value << " enqueued to queue.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }

        cout << arr[front] << " dequeued from queue.\n";

        if (front == rear) {  
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return -1;
        }
        return arr[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;
    int choice, value;

    do {
        cout << "\n--- Circular Queue Operations Menu ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Check if Empty\n6. Check if Full\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            }
            case 2: {
                q.dequeue();
                break;
            }
            case 3: {
                value = q.peek();
                if (value != -1)
                    cout << "Front element: " << value << endl;
                break;
            }
            case 4: {
                q.display();
                break;
            }
            case 5: {
                cout << (q.isEmpty() ? "Queue is empty.\n" : "Queue is not empty.\n");
                break;
            }
            case 6: {
                cout << (q.isFull() ? "Queue is full.\n" : "Queue is not full.\n");
                break;
            }
            case 7: {
                cout << "Exiting...\n";
                break;
            }
            default: {
                cout << "Invalid choice! Try again.\n";
            }
        }
    } while (choice != 7);

    return 0;
}
