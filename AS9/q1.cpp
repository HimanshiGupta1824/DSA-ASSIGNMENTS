#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i, bool increasing=true) {
    int extremum = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (increasing) {
        if (l < n && arr[l] > arr[extremum]) extremum = l;
        if (r < n && arr[r] > arr[extremum]) extremum = r;
    } else {
        if (l < n && arr[l] < arr[extremum]) extremum = l;
        if (r < n && arr[r] < arr[extremum]) extremum = r;
    }

    if (extremum != i) {
        swap(arr[i], arr[extremum]);
        heapify(arr, n, extremum, increasing);
    }
}

void heapSort(int arr[], int n, bool increasing=true) {
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i, increasing);

    for (int i = n-1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, increasing);
    }
}

int main() {
    int arr[] = {20, 10, 30, 5, 40};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Original array: ";
    for(int x : arr) cout << x << " ";
    cout << endl;

    heapSort(arr, n, true);
    cout << "Sorted (Increasing): ";
    for(int x : arr) cout << x << " ";
    cout << endl;

    heapSort(arr, n, false);
    cout << "Sorted (Decreasing): ";
    for(int x : arr) cout << x << " ";
    cout << endl;
}
