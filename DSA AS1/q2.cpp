#include <iostream>
using namespace std;

int main(){
    int arr[100] = {}, n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(arr[i] == arr[j]){
                for(int k = j+1; k < n; k++) arr[k-1] = arr[k];
                j--; n--;
            }
        }
    }
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}
