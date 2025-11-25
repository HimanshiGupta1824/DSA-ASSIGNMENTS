#include<iostream>
using namespace std;
int main(){
    // n= 11 
int arr[10]  = {8,9,6,5,7,4,2,3,1,10};

int x;
cout<<"enter the element to be searched"<<" ";
cin>>x;


// sorting the array before binary search
for(int i = 1;i<=9;i++){
    for(int j = 0;j<=9-i;j++){
        if(arr[j]>arr[j+1]){
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
        }
    }
}

// sorted array 
for(int i =0;i<10;i++){
    cout<<arr[i]<<" ";
}
cout<<endl;


//binary search
int i = 0;
int j = 9;
bool found = false;
while(i<=j){
    int mid = (i+j)/2;
    if(arr[mid]==x) {
        found = true;
        cout<<"element in sorted array at index no "<<mid;
        break;
    }
    else if(arr[mid]>x)  j = mid-1;
    else i = mid+1;
}

if (found == false) {
    cout<<"element not found";
}

return 0;
}