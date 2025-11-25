#include <iostream>
using namespace std;

void create(int arr[], int n){
    for(int i = 0; i < n; i++) cin >> arr[i];
}

void display(int arr[], int n){
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

void insert(int arr[], int &n, int idx, int val){
    for(int i = n-1; i >= idx; i--) arr[i+1] = arr[i];
    arr[idx] = val;
    n++;
}

void del(int arr[], int &n, int idx){
    for(int i = idx+1; i < n; i++) arr[i-1] = arr[i];
    n--;
}

void search(int arr[], int n, int l){
    int i;
    for(i = 0; i < n; i++){
        if(arr[i] == l){
            cout << i << endl;
            break;
        }
    }
    if(i == n) cout << "cant find\n";
}

int main(){
    int n, arr[100] = {}, option;
    cout << "enter no of elements: ";
    cin >> n;
    do{
        cout << "\n1.CREATE\n2.DISPLAY\n3.INSERT\n4.DELETE\n5.LINEAR SEARCH\n6.EXIT\n";
        cout << "enter option: ";
        cin >> option;
        switch(option){
            case 1: create(arr,n); break;
            case 2: display(arr,n); break;
            case 3:{
                int k, v;
                cout << "Enter index: "; cin >> k;
                cout << "Enter value: "; cin >> v;
                if(k >= 0 && k <= n){ insert(arr,n,k,v); display(arr,n); }
                else cout << "Invalid index!\n";
                break;
            }
            case 4:{
                int k;
                cout << "Enter index: "; cin >> k;
                if(k >= 0 && k < n){ del(arr,n,k); display(arr,n); }
                else cout << "Invalid index!\n";
                break;
            }
            case 5:{
                int l;
                cout << "element to be searched: "; cin >> l;
                search(arr,n,l);
                break;
            }
            case 6: cout << "exit\n"; break;
        }
    } while(option != 6);
    return 0;
}
