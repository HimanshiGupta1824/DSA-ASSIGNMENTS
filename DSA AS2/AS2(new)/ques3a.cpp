#include<iostream>
using namespace std;
int main(){
int arr[10]  = {8,9,6,5,7,4,2,3,1,10};

int x;
cout<<"enter the element to be searched"<<" ";
cin>>x;

// linear search
bool found = false;
for(int i = 0;i<109
    ;i++){
    if(arr[i] == x) {
         found = true;
         cout<<" element found at index"<<" "<<i;
         break;

    }
}
if(!found) cout <<" element not found";

return 0;
}