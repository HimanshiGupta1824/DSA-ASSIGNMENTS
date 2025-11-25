#include <iostream>
using namespace std;

int main(){
    int arr[100][100] = {}, r, c;
    cin >> r >> c;
    for(int i = 0; i < r; i++) for(int j = 0; j < c; j++) cin >> arr[i][j];
    int transposed[100][100] = {};
    for(int i = 0; i < r; i++) for(int j = 0; j < c; j++) transposed[j][i] = arr[i][j];
    for(int i = 0; i < c; i++){
        for(int j = 0; j < r; j++) cout << transposed[i][j] << " ";
        cout << endl;
    }
    return 0;
}
