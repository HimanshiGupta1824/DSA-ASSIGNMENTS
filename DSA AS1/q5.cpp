#include <iostream>
using namespace std;

int main(){
    int arr[100][100] = {}, r, c;
    cin >> r >> c;
    for(int i = 0; i < r; i++) for(int j = 0; j < c; j++) cin >> arr[i][j];
    for(int i = 0; i < r; i++){
        int sum = 0;
        for(int j = 0; j < c; j++) sum += arr[i][j];
        cout << "sum of row " << i << " is " << sum << endl;
    }
    for(int j = 0; j < c; j++){
        int sum = 0;
        for(int i = 0; i < r; i++) sum += arr[i][j];
        cout << "sum of column " << j << " is " << sum << endl;
    }
    return 0;
}
