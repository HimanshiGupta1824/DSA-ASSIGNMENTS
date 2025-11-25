#include <iostream>
#include <queue>
using namespace std;

int main() {
    string str;
    cin >> str;

    queue<char> q;
    int freq[256] = {0};

    for (char ch : str) {
        freq[ch]++;
        q.push(ch);

        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }

        if (q.empty()) {
            cout << -1 << " ";
        } else {
            cout << q.front() << " ";
        }
    }

    cout << endl;
    return 0;
}
